# Lyrenhold – Gran Torneo de la Arena

Proyecto final del curso **Programación Orientada a Objetos 2025-2**.  
El objetivo es implementar un sistema en C++ que simule combates por turnos en el universo ficticio de **Lyrenhold**, aplicando de forma explícita los cuatro pilares de la POO: **abstracción, encapsulamiento, herencia y polimorfismo**. [attached_file:34]

---

## Descripción general

En la ciudad de Lyrenhold se celebra cada año el **Gran Torneo de la Arena**, donde distintos **gremios de aventureros (guilds)** compiten por honor y gloria. [attached_file:34]  
El sistema gestiona una *guild* de héroes, una serie de oponentes y un inventario de objetos mágicos, permitiendo simular combates por turnos. [attached_file:34]

El proyecto busca evidenciar:

- Diseño orientado a objetos con clases y relaciones coherentes.
- Uso de herencia y polimorfismo para representar distintos tipos de personajes y comportamientos.
- Razonamiento y evolución del diseño a lo largo del desarrollo, no solo el producto final. [attached_file:34]

---

## Características principales

### Héroes y oponentes

- Cada personaje (héroe u oponente) tiene: **nombre, nivel, vida, ataque, defensa y rol**. [attached_file:34]
- Los **héroes** pertenecen a la *guild* del jugador, los **oponentes** a guilds rivales, con conjunto de atributos similar. [attached_file:34]
- El sistema debe permitir crear nuevos tipos de roles sin romper el diseño general (extensibilidad). [attached_file:34]

Roles recomendados de ejemplo:

- **Guerrero**: daño físico estable, mayor vida y defensa, posibilidad de golpes críticos. [attached_file:34]
- **Mago**: daño elevado, baja defensa, ataques que pueden tener efectos variables (daño extra, quemar, etc.). [attached_file:34]
- **Sanador**: se centra en curar aliados, con efectividad aleatoria de las curaciones. [attached_file:34]
---

## Inventario y objetos mágicos

Antes de cada torneo, la *guild* recibe un conjunto limitado de **objetos mágicos** almacenados en un **inventario global**. [attached_file:34]

Reglas principales:

- Cada héroe puede portar hasta **dos objetos por combate**. [attached_file:34]
- Cada objeto solo puede usarse una vez por batalla; tras usarse se descuenta del inventario global. [attached_file:34]
- Objetos no utilizados pueden conservarse para futuros combates. [attached_file:34]

Flujo del inventario:

1. **Preparación**: asignar o retirar objetos a héroes antes del combate, respetando stock global. [attached_file:34]
2. **Combate**: solo los héroes con objeto asignado pueden usarlo, una vez por batalla, mostrando su efecto en consola. [attached_file:34]
3. **Post–combate**: los objetos usados se eliminan del inventario global; los no usados permanecen. [attached_file:34]

Ejemplos de objetos mágicos:

- **Poción de Vida**: restaura vida en un rango aleatorio entre 20–40 puntos. [attached_file:34]
- **Amuleto de Furia**: aumenta el ataque del héroe durante un turno +5 a +10 con efecto temporal. [attached_file:34]
- **Escudo Bendito**: incrementa la defensa de forma temporal en un rango aleatorio  +10 a +20. [attached_file:34]

El equipo debe definio**tres objetos adicionales** siendo estos: pocion vida, pocion veneno, cancelacion. [attached_file:34]

### CRUD de objetos mágicos

El inventario global soporta:

- **registrar tipo de objeto, efecto y stock inicial.
- **Listar/Consultar**: ver detalles del objeto y su stock.
- **Actualizar**: modificar stock. [attached_file:34]
- **Asignar/Retirar**: asignar descuenta stock; retirar lo devuelve si el objeto no ha sido usado. [attached_file:34]

---

## Gestión de la Guild

Al iniciar el programa:

- Se crea automáticamente un **menu de personajes**, mostrando un mensaje de bienvenida y indicando que hay que seleccionar 3 heroes. [attached_file:34]
- luego se crea automáticamente un **inventario**, mostrando un mensaje indicando que hay que seleccionar máximo 2 objetos mágicos por los personajes seleccionados anteriormente.  [attached_file:34]

Funcionalidades:

- Listar héroes y enemigos.
- Agregar nuevos personajes.
- Consultar detalles de un personaje.
- Retirar personajes de la guild. [attached_file:34]

Validaciones:

- No permite retirar héroes inexistentes.
- Al retirar un héroe como para ese momento no ha muerto vuelve a estar disponible para escogerse. [attached_file:34]

---

## Sistema de combate en la Arena

La **Arena** es donde se enfrentan los equipos en un combate por turnos. [attached_file:34]

Características:

- Turnos alternados entre 3 héroes y 3 oponentes.
- En cada turno un personaje puede: **atacar, defender o usar un objeto mágico**, según su rol. [attached_file:34]
- Los resultados incluyen **aleatoriedad controlada**:
    - Variación del daño (por ejemplo ±10%).
    - Probabilidad de golpes críticos.
    - Efectividad variable de curaciones y defensas.
    - Efectos aleatorios de objetos mágicos. [attached_file:34]

Condiciones de fin de combate:

- Un personaje es derrotado cuando su vida llega a 0.
- Un equipo es eliminado cuando todos sus integrantes están derrotados.
- El combate concluye cuando solo queda con vida al menos un personaje de uno de los equipos. [attached_file:34]

Al finalizar, la Arena muestra un resumen:

- Nombre del equipo ganador.
- Heroes supervivientes.
- rivales supervivientes.
- Número total de turnos.
- numero de Objetos mágicos utilizados. [attached_file:34]

---

Diagrama de clases: 

classDiagram

class Personaje {
    -int id
    -String nombrePersonaje
    -string descripcion
    -String tipo        
    -String rol      
    -int nivel
    -int vida
    -int ataque
    -int defensa
    +realizarAccion(objetivo:Personaje)
    +ejecutarAccion(usuario:Personaje, objetivo:Personaje)
    +usarObjeto(nombreObjeto:String)
    +estaVivo() bool
}

class Guerrero {
    -double GolpeCritico
    +getGolpeCritico()
    +setGolpeCritico(prob:double)
    +realizarAccion(objetivo:Personaje)
}

class Mago {
    -double IgnorarDefensa
    +getIgnorarDefensa()
    +setIgnorarDefensa(p:double)
    +realizarAccion(objetivo:Personaje)
}

class Sanador {
    -int minCura
    -int maxCura
    +getMinCura()
    +getMaxCura()
    +setMinCura(c:int)
    +setMaxCura(c:int)
    +realizarAccion(objetivo:Personaje)
}

Personaje <|-- Guerrero
Personaje <|-- Mago
Personaje <|-- Sanador

class ObjetoMagico {
    -String nombreObjetMagico
    -string Descripcion
    +usar(personaje:Personaje)
}

class PocionVida {
    -int minCuracion
    -int maxCuracion
}

class AmuletoFuria {
    -int minAumentoDano
    -int maxAumentoDano
}

class EscudoBendito {
    -int minDefensa
    -int maxDefensa
}

class EscudoReflectivo {
    -int cantidadReflejo
}

class PocionVeneno {
    -int danoPorTurno
}

class Cancelacion {
    -int turnoCancelado
}

ObjetoMagico <|-- PocionVida
ObjetoMagico <|-- AmuletoFuria
ObjetoMagico <|-- EscudoBendito
ObjetoMagico <|-- EscudoReflectivo
ObjetoMagico <|-- PocionVeneno
ObjetoMagico <|-- Cancelacion

Inventario --> "*" ObjetoMagico
Inventario --> "0..2" Personaje 

class Inventario {
    -Map~String,int~ stock
    -Map<Personaje,List<ObjetoMagico>> asignados
    +crear(obj:ObjetoMagico, cant:int)
    +listar()
    +consultar(nombre:String)
    +actualizarStock(nombre:String, cant:int)
    +eliminar(nombre:String)
    +asignar(p:Personaje, obj:ObjetoMagico)
}

class Guild {
    -String nombre
    -string tipo
    -List~Personaje~ heroes
    -List~Personaje~ oponentes
    -Inventario inventario
    +agregarPersonaje(p:Personaje)
    +retirarPersonaje(id:int)
    +listarPersonajes()
    +consultarPersonaje(id:int)
}

Guild --> "*" Personaje
Guild --> "1" Inventario

class Arena {
    -int turnoActual
    -Guild guild
    -Inventario inventario
    +iniciarCombate(guild:Guild)
    +ejecutarTurno()
    +procesarAccion(p:Personaje)
    +obtenerHeroesVivos() List~Personaje~
    +obtenerOponentesVivos() List~Personaje~
    +equipoDerrotado(equipo:List~Personaje~) bool
    +verificarFinCombate() bool
    +verificarGanador() String
}

Arena --> Guild
Arena --> "*" Personaje
Arena --> Inventario
