#include "Arena.h"
#include "Guild.h"
#include "Personaje.h"
#include "Inventario.h"
#include <iostream>
#include <cstdlib>
#include "EscudoReflectivo.h"
#include "ObjetoMagico.h"

using std::cout;
using std::endl;
using std::cin;

Arena::Arena() : turnoActual(1), guild(nullptr), inventario(nullptr), objetosUsadosContador(0) {}

void Arena::iniciarCombate(Guild* g) {
    guild = g;
    inventario = g->getInventario();
    turnoActual = 1;
    cout << "\n=== EMPIEZA EL COMBATE ===\n";
}

vector<Personaje*> Arena::obtenerHeroesVivos() {
    vector<Personaje*> vivos;
    for (auto p : guild->getHeroes()) if (p->estaVivo()) vivos.push_back(p);
    return vivos;
}

vector<Personaje*> Arena::obtenerOponentesVivos() {
    vector<Personaje*> vivos;
    for (auto p : guild->getOponentes()) if (p->estaVivo()) vivos.push_back(p);
    return vivos;
}

bool Arena::verificarFinCombate() {
    bool heroesMuertos = true;
    for (auto p : guild->getHeroes()) if (p->estaVivo()) { heroesMuertos = false; break; }
    bool oponentesMuertos = true;
    for (auto p : guild->getOponentes()) if (p->estaVivo()) { oponentesMuertos = false; break; }
    return heroesMuertos || oponentesMuertos;
}

string Arena::verificarGanador() {
    bool heroesMuertos = true;
    for (auto p : guild->getHeroes()) if (p->estaVivo()) { heroesMuertos = false; break; }
    bool oponentesMuertos = true;
    for (auto p : guild->getOponentes()) if (p->estaVivo()) { oponentesMuertos = false; break; }
    if (oponentesMuertos) return "Guild del jugador";
    if (heroesMuertos) return "Guild rival";
    return "Ninguno";
}

void Arena::ejecutarTurnoUsuario() {
    auto heroes = obtenerHeroesVivos();
    auto oponentes = obtenerOponentesVivos();
    if (heroes.empty() || oponentes.empty()) return;

    cout << "\n===== TURNO " << turnoActual << " HEROES =====\n";

    for (auto her : heroes) {
        her->procesarEfectosAlInicioTurno();
        if (!her->estaVivo()) continue;
        if (her->estaCancelado()) {
            cout << her->getNombre() << " esta incapacitado por efecto de la cancelacion lo cual hace que pierda su turno.\n";
            continue;
        }

        cout << "\nAccion para " << her->getNombre() << " (ID " << her->getId() << "):\n";
        cout << "1) Atacar\n";
        cout << "2) Usar objeto magico\n";
        cout << "3) Pasar turno\n";
        cout << "Opcion: ";
        int op;
        std::cin >> op;
        if (op == 1) {

            auto oponentesVivos = obtenerOponentesVivos();
            cout << "Elija objetivo:\n";
            for (size_t i = 0; i < oponentesVivos.size(); ++i) {
                cout << i+1 << ") " << oponentesVivos[i]->getNombre() << " (Vida: " << oponentesVivos[i]->getVida() << ")\n";
            }
            int sel; std::cin >> sel;
            if (sel >= 1 && sel <= (int)oponentesVivos.size()) {
                Personaje* objetivo = oponentesVivos[sel-1];
                her->realizarAccion(objetivo);

                ObjetoMagico* reflect = inventario->buscarAsignado(objetivo, "EscudoReflectivo");
                if (reflect) {

                    EscudoReflectivo* er = dynamic_cast<EscudoReflectivo*>(reflect);
                    if (er) {
                        int reflejo = er->getCantidadReflejo();
                        her->setVida(her->getVida() - reflejo);
                        cout << objetivo->getNombre() << " refleja " << reflejo << " de dano a " << her->getNombre() << ".\n";
                    }
                }
            }
        } else if (op == 2) {

            auto list = inventario->listarAsignados(her);
            if (list.empty()) {
                cout << "No tiene objetos asignados.\n";
            } else {
                cout << "Objetos asignados:\n";
                for (size_t i = 0; i < list.size(); ++i) {
                    cout << i+1 << ") " << list[i] << "\n";
                }
                cout << "Elija objeto a usar: ";
                int sel; std::cin >> sel;
                if (sel >= 1 && sel <= (int)list.size()) {
                    string nombreObj = list[sel-1];

                    if (nombreObj == "PocionVida") {
                        cout << her->getNombre() << " usa " << nombreObj << ".\n";
                        inventario->usarAsignado(her, nombreObj);
                        objetosUsadosContador++;
                    } else if (nombreObj == "AmuletoFuria" || nombreObj == "EscudoBendito") {
                        cout << her->getNombre() << " usa " << nombreObj << ".\n";
                        inventario->usarAsignado(her, nombreObj);
                        objetosUsadosContador++;
                    } else if (nombreObj == "PocionVeneno" || nombreObj == "Cancelacion") {

                        auto oponentesVivos = obtenerOponentesVivos();
                        cout << "Elija objetivo enemigo:\n";
                        for (size_t i = 0; i < oponentesVivos.size(); ++i)
                            cout << i+1 << ") " << oponentesVivos[i]->getNombre() << " (Vida: " << oponentesVivos[i]->getVida() << ")\n";
                        int sel2; std::cin >> sel2;
                        if (sel2 >= 1 && sel2 <= (int)oponentesVivos.size()) {
                            Personaje* objetivo = oponentesVivos[sel2-1];
                            cout << her->getNombre() << " usa " << nombreObj << " sobre " << objetivo->getNombre() << ".\n";

                            ObjetoMagico* objptr = inventario->buscarAsignado(her, nombreObj);
                            if (objptr) {
                                objptr->usar(objetivo);
                                inventario->usarAsignado(her, nombreObj);
                                objetosUsadosContador++;
                            }
                        }
                    } else if (nombreObj == "EscudoReflectivo") {
                        cout << her->getNombre() << " activa EscudoReflectivo.\n";
                        inventario->usarAsignado(her, nombreObj);
                        objetosUsadosContador++;
                    } else {
                        cout << "Objeto no reconocido.\n";
                    }
                }
            }
        } else {
            cout << her->getNombre() << " pasa su turno.\n";
        }

        if (verificarFinCombate()) return;
    }

    turnoActual++;
}

void Arena::ejecutarTurnoEnemigos() {
    auto heroes = obtenerHeroesVivos();
    auto oponentes = obtenerOponentesVivos();
    if (heroes.empty() || oponentes.empty()) return;

    cout << "\n===== TURNO " << turnoActual << " (OPONENTES) =====\n";

    for (auto ene : oponentes) {
        ene->procesarEfectosAlInicioTurno();
        if (!ene->estaVivo()) continue;
        if (ene->estaCancelado()) {
            cout << ene->getNombre() << " esta incapacitado y pierde su turno.\n";
            continue;
        }

        auto heroesVivos = obtenerHeroesVivos();
        if (heroesVivos.empty()) return;
        Personaje* objetivo = heroesVivos[rand() % heroesVivos.size()];
        cout << ene->getNombre() << " actua sobre " << objetivo->getNombre() << ".\n";
        ene->realizarAccion(objetivo);

        ObjetoMagico* reflect = inventario->buscarAsignado(objetivo, "EscudoReflectivo");
        if (reflect) {
            EscudoReflectivo* er = dynamic_cast<EscudoReflectivo*>(reflect);
            if (er) {
                int reflejo = er->getCantidadReflejo();
                ene->setVida(ene->getVida() - reflejo);
                cout << objetivo->getNombre() << " refleja " << reflejo << " de dano a " << ene->getNombre() << ".\n";
            }
        }
        if (verificarFinCombate()) return;
    }

    turnoActual++;
}

void Arena::mostrarResumenFinal() {
    cout << "\n=== FIN DEL COMBATE ===\n";
    cout << "Equipo ganador: " << verificarGanador() << "\n";
    cout << "Heroes supervivientes:\n";
    for (auto h : obtenerHeroesVivos()) cout << "- " << h->getNombre() << "\n";
    cout << "Oponentes supervivientes:\n";
    for (auto o : obtenerOponentesVivos()) cout << "- " << o->getNombre() << "\n";
    cout << "Numero total de turnos: " << turnoActual << "\n";
    cout << "Objetos magicos usados: " << objetosUsadosContador << "\n";
}

int Arena::getObjetosUsados() const { return objetosUsadosContador; }
