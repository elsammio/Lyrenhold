#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "src\Guerrero.h"
#include "src\Mago.h"
#include "src\Sanador.h"
#include "src\PocionVida.h"
#include "src\AmuletoFuria.h"
#include "src\EscudoBendito.h"
#include "src\EscudoReflectivo.h"
#include "src\PocionVeneno.h"
#include "src\Cancelacion.h"
#include "src\Inventario.h"
#include "src\Guild.h"
#include "src\Arena.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void mostrarPlantillaPersonajesDisponibles() {
    cout << "Personajes disponibles:\n";
    cout << "1) Guerrero Dante\n";
    cout << "2) Guerrero Baltazar\n";
    cout << "3) Guerrero Lalo\n";
    cout << "4) Mago Motas\n";
    cout << "5) Mago Darwin\n";
    cout << "6) Mago Mordecai\n";
    cout << "7) Sanador Pacho\n";
    cout << "8) Sanador Lucho\n";
    cout << "9) Sanadora Lola\n";
    cout << "Retirar: Esta opcion te permite retirar al ultimo Heroe que escogiste y que puedas escoger otro.\n";
}

Personaje* crearPersonajePorOpcion(int opt, int id) {
    if (opt == 1) return new Guerrero(id, "Dante", "Heroe", "Guerrero", 3, 120, 25, 15, 0.30);
    if (opt == 2) return new Guerrero(id, "Baltazar", "Heroe", "Guerrero", 4, 130, 30, 20, 0.30);
    if (opt == 3) return new Guerrero(id, "Lalo", "Heroe", "Guerrero", 2, 110, 20, 10, 0.30);
    if (opt == 4) return new Mago(id, "Motas", "Heroe", "Mago", 3, 80, 35, 5, 0.40);
    if (opt == 5) return new Mago(id, "Darwin", "Heroe", "Mago", 4, 90, 40, 6, 0.40);
    if (opt == 6) return new Mago(id, "Mordecai", "Heroe", "Mago", 5, 100, 45, 7, 0.40);
    if (opt == 7) return new Sanador(id, "Pacho", "Heroe", "Sanador", 3, 90, 10, 15, 15, 30);
    if (opt == 8) return new Sanador(id, "Lucho", "Heroe", "Sanador", 3, 90, 10, 20, 15, 30);
    if (opt == 9) return new Sanador(id, "Lola", "Heroe", "Sanador", 3, 90, 10, 25, 15, 30);
    return nullptr;
}

Personaje* crearOponentePorIndice(int idx) {
    if (idx == 1) return new Guerrero(101, "Nesquit","Oponente", "Guerrero", 4, 140, 22, 12, 0.20);
    if (idx == 2) return new Mago(102, "Creek","Oponente", "Mago", 4, 100, 32, 4, 0.35);
    if (idx == 3) return new Sanador(103, "Tito", "Oponente", "Sanador", 4, 100, 8, 6, 10, 25);
    return nullptr;
}

int main() {
    std::srand((unsigned)std::time(nullptr));

    Guild guild("Guardianes de Lyrenhold", "Jugador");
    Inventario* inv = guild.getInventario();

    inv->crear(new PocionVida("PocionVida", "Restaura entre 20 y 40 puntos de vida", 20, 40), 3);
    inv->crear(new AmuletoFuria("AmuletoFuria", "Aumenta el ataque entre 5 y 10 puntos", 5, 10), 2);
    inv->crear(new EscudoBendito("EscudoBendito", "Aumenta defensa entre 10 y 20 puntos.", 10, 20), 2);
    inv->crear(new EscudoReflectivo("EscudoReflectivo", "Refleja el dano recibido.", 15), 1);
    inv->crear(new PocionVeneno("PocionVeneno", "Resta vida durante 3 turnos.", 12), 2);
    inv->crear(new Cancelacion("Cancelacion", "incapacita al rival por el resto de la partida", 1), 1);

    cout << "Bienvenido al Torneo de Lyrenhold.\n";
    cout << "Selecciona 3 heroes para tu guild.\n";

    int seleccion;
    int idCounter = 1;
    int chosen = 0;

    vector<int> usados;

    while (chosen < 3) {
        mostrarPlantillaPersonajesDisponibles();
        cout << "Elige al heroe numero " << (chosen+1) << ": ";
        cin >> seleccion;

        if (cin.fail()) {
            cin.clear();
            string palabra;
            cin >> palabra;

            if (palabra == "Retirar") {
                if (chosen == 0) {
                    cout << "No hay heroes para retirar.\n";
                } else {
                    Personaje* ultimo = guild.getHeroes().back();
                    cout << "Se retiro del equipo " << ultimo->getNombre() << endl;

                    usados.pop_back();

                    guild.eliminarUltimoHeroe();
                    chosen--;
                    idCounter--;
                }
                continue;
            } else {
                cout << "Opcion invalida.\n";
                continue;
            }
        }

        if (std::find(usados.begin(), usados.end(), seleccion) != usados.end()) {
            cout << " Ese heroe ya fue escogido, elige otro.\n";
            continue;
        }

        Personaje* p = crearPersonajePorOpcion(seleccion, idCounter++);
        if (p) {
            guild.agregarHeroe(p);
            usados.push_back(seleccion);
            chosen++;
            cout << p->getNombre() << " agregado a tu guild.\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    }
    guild.agregarOponente(crearOponentePorIndice(1));
    guild.agregarOponente(crearOponentePorIndice(2));
    guild.agregarOponente(crearOponentePorIndice(3));

    cout << "\nAhora puedes asignar maximo 2 objetos por personaje.\n";

    for (Personaje* p : guild.getHeroes()) {
        cout << "\nAsignando objetos a " << p->getNombre() << " maximo 2 objetos\n";
        int asignadas = 0;

        while (asignadas < 2) {
            cout << "\nInventario actual:\n";
            inv->listar();
            cout << "- Retirar: Retira el ultimo objeto magico escogido.\n";

            cout << "Ingrese el nombre del objeto a asignar: ";
            string nombre;
            cin >> nombre;

            if (nombre == "Retirar") {
                auto lista = inv->listarAsignados(p);
                if (lista.empty()) {
                    cout << "No hay objetos para retirar.\n";
                } else {
                    string ultimo = lista.back();
                    inv->retirar(p, ultimo);
                    cout << "Se retiro el objeto " << ultimo << endl;
                    asignadas--;
                }
                continue;
            }

            if (nombre == "0") break;

            ObjetoMagico* nuevo = nullptr;
            if (nombre == "PocionVida") nuevo = new PocionVida("PocionVida","",20,40);
            else if (nombre == "AmuletoFuria") nuevo = new AmuletoFuria("AmuletoFuria","",5,10);
            else if (nombre == "EscudoBendito") nuevo = new EscudoBendito("EscudoBendito","",10,20);
            else if (nombre == "EscudoReflectivo") nuevo = new EscudoReflectivo("EscudoReflectivo","",15);
            else if (nombre == "PocionVeneno") nuevo = new PocionVeneno("PocionVeneno","",12);
            else if (nombre == "Cancelacion") nuevo = new Cancelacion("Cancelacion","",1);
            else {
                cout << "Nombre invalido.\n";
                continue;
            }

            bool ok = inv->asignar(p, nuevo);

            if (!ok) {
                cout << "No se pudo asignar.\n";
                delete nuevo;
            } else {
                cout << "El objeto se asigno.\n";
                asignadas++;
            }
        }
    }

    int opcion = -1;
    Arena arena;

    do {
        cout << "\n=================================\n";
        cout << "   TORNEO EN LA ARENA DE LYRENHOLD\n";
        cout << "=================================\n";
        cout << "1. Listar personajes, heroes y oponentes\n";
        cout << "2. Listar objetos magicos del inventario\n";
        cout << "3. Iniciar combate en la Arena\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                guild.listarHeroes();
                guild.listarOponentes();
                break;

            case 2:
                cout << "\n=== OBJETOS MAGICOS EN INVENTARIO ===\n";
                inv->listar();
                break;

            case 3:
                arena.iniciarCombate(&guild);
                while (!arena.verificarFinCombate()) {
                    arena.ejecutarTurnoUsuario();
                    if (arena.verificarFinCombate()) break;
                    arena.ejecutarTurnoEnemigos();
                }
                arena.mostrarResumenFinal();
                break;

            case 0:
                cout << "Fin del juego, Muchas gracias por jugar.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
