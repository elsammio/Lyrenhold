# Lyrenhold – Gran Torneo de la Arena

Proyecto final del curso **Programación Orientada a Objetos 2025-2**.  
El objetivo es implementar un sistema en C++ que simule combates por turnos en el universo ficticio de **Lyrenhold**, aplicando de forma explícita los cuatro pilares de la POO: **abstracción, encapsulamiento, herencia y polimorfismo**. [attached_file:34]

---

## Descripción general

En la ciudad de Lyrenhold se celebra cada año el **Gran Torneo de la Arena**, donde distintos **gremios de aventureros (guilds)** compiten por honor y gloria. [attached_file:34]  
El sistema gestiona una *guild* de héroes, una serie de oponentes y un inventario de objetos mágicos, permitiendo simular combates por turnos con resultados parcialmente aleatorios. [attached_file:34]

El proyecto busca evidenciar:

- Diseño orientado a objetos con clases y relaciones coherentes.
- Uso de herencia y polimorfismo para representar distintos tipos de personajes y comportamientos.
- Razonamiento y evolución del diseño a lo largo del desarrollo, no solo el producto final. [attached_file:34]

---

## Características principales

### Héroes y oponentes

- Cada personaje (héroe u oponente) tiene al menos: **nombre, nivel, vida, ataque, defensa y rol**. [attached_file:34]
- Los **héroes** pertenecen a la *guild* del jugador, los **oponentes** a guilds rivales, con conjunto de atributos similar. [attached_file:34]
- El sistema debe permitir crear nuevos tipos de roles sin romper el diseño general (extensibilidad). [attached_file:34]

Roles recomendados de ejemplo:

- **Guerrero**: daño físico estable, mayor vida y defensa, posibilidad de golpes críticos. [attached_file:34]
- **Mago**: daño elevado, baja defensa, ataques que pueden ignorar parcialmente la defensa o tener efectos variables (daño extra, quemar, etc.). [attached_file:34]
- **Sanador**: se centra en curar aliados, con efectividad aleatoria de las curaciones. [attached_file:34]

Se pueden agregar otros roles (por ejemplo, **Hechicero Oscuro**, **Paladín**) siempre que mantengan coherencia con la lógica del sistema. [attached_file:34]

---

## Inventario y objetos mágicos

Antes de cada torneo, la *guild* recibe un conjunto limitado de **objetos mágicos** (reliquias de batalla) almacenados en un **inventario global**. [attached_file:34]

Reglas principales:

- Cada héroe puede portar hasta **dos objetos por combate**. [attached_file:34]
- Cada objeto solo puede usarse una vez por batalla; tras usarse se descuenta del inventario global. [attached_file:34]
- Objetos no utilizados pueden conservarse para futuros combates. [attached_file:34]

Flujo del inventario:

1. **Preparación**: asignar o retirar objetos a héroes antes del combate, respetando stock global. [attached_file:34]
2. **Combate**: solo los héroes con objeto asignado pueden usarlo, una vez por batalla, mostrando su efecto en consola. [attached_file:34]
3. **Post–combate**: los objetos usados se eliminan del inventario global; los no usados permanecen. [attached_file:34]

Ejemplos de objetos mágicos:

- **Poción de Vida**: restaura vida en un rango aleatorio (p. ej. 20–40 puntos). [attached_file:34]
- **Amuleto de Furia**: aumenta el ataque del héroe durante un turno (p. ej. +5 a +10) con efecto temporal. [attached_file:34]
- **Escudo Bendito**: incrementa la defensa de forma temporal en un rango aleatorio (p. ej. +10 a +20). [attached_file:34]

El equipo debe definir al menos **tres objetos adicionales** coherentes con el mundo del torneo. [attached_file:34]

### CRUD de objetos mágicos

El inventario global soporta al menos:

- **Crear**: registrar tipo de objeto, efecto y stock inicial.
- **Listar/Consultar**: ver detalles del objeto (rango de efecto, usos, stock).
- **Actualizar**: modificar stock y, opcionalmente, parámetros del efecto (debe explicarse en este README). [attached_file:34]
- **Eliminar**: solo si el stock es 0.
- **Asignar/Retirar**: asignar descuenta stock; retirar lo devuelve si el objeto no ha sido usado. [attached_file:34]

---

## Gestión de la Guild

Al iniciar el programa:

- Se crea automáticamente una **Guild del jugador**, mostrando un mensaje de bienvenida y el estado inicial de sus héroes. [attached_file:34]
- Se cargan héroes base y enemigos con atributos precargados, para poder ejecutar una batalla sin ingresar datos manualmente. [attached_file:34]

Funcionalidades mínimas:

- Listar héroes y enemigos.
- Agregar nuevos personajes.
- Consultar detalles de un personaje.
- Retirar personajes de la guild o del conjunto de enemigos, evitando duplicados y garantizando identificadores únicos. [attached_file:34]

Validaciones esperadas:

- No permitir retirar héroes inexistentes.
- No iniciar batallas sin héroes vivos disponibles.
- Al retirar un héroe, debe dejar de aparecer en listados y selección para la arena. [attached_file:34]

---

## Sistema de combate en la Arena

La **Arena** es donde se enfrentan los equipos en un combate por turnos. [attached_file:34]

Características:

- Turnos alternados entre héroes y oponentes.
- En cada turno un personaje puede: **atacar, curar, defender o usar un objeto mágico**, según su rol. [attached_file:34]
- Los resultados incluyen **aleatoriedad controlada**:
    - Variación del daño (por ejemplo ±10%).
    - Probabilidad de golpes críticos o fallos.
    - Efectividad variable de curaciones y defensas.
    - Efectos aleatorios de objetos mágicos. [attached_file:34]

Condiciones de fin de combate:

- Un personaje es derrotado cuando su vida llega a 0 o menos.
- Un equipo es eliminado cuando todos sus integrantes están derrotados.
- El combate concluye cuando solo queda con vida al menos un personaje de uno de los equipos. [attached_file:34]

Al finalizar, la Arena debe mostrar un resumen:

- Nombre del equipo ganador.
- Héroes supervivientes.
- Número total de turnos.
- Objetos mágicos utilizados. [attached_file:34]

---

## Persistencia de datos

El sistema debe **guardar y cargar** al menos **una categoría de información** en un archivo **JSON** (por ejemplo, héroes, oponentes, objetos o batallas). [attached_file:34]

- El equipo elige qué categoría persistir y la documenta aquí.
- La lectura/escritura se hace desde consola, sin librerías externas de UI. [attached_file:34]

---

## Alcance técnico

Requisitos técnicos del proyecto:

- Lenguaje: **C++**, estándar actual del curso.
- Estructuras de datos: uso visible de `std::vector` y `std::unordered_map`. [attached_file:34]
- Memoria: manejo con punteros crudos cuando aplique, liberación explícita. [attached_file:34]
- Interfaz: ejecución por **consola**, sin frameworks gráficos externos.
- Persistencia: una categoría en formato **JSON**. [attached_file:34]
- Trabajo en equipo: proyectos en equipos de **2 personas**, con uso continuo de **git** y **GitHub**. [attached_file:34]

Cada *commit* debe incluir un mensaje con la estructura:

> Qué cambié → Por qué lo hice → Qué espero que mejore. [attached_file:34]

---

## Uso de IA (política del curso)

**Permitido**: [attached_file:34]

- Consultar dudas de sintaxis C++, STL, lectura/escritura de archivos.
- Pedir ejemplos para entender cómo resolver aspectos del proyecto.
- Mejorar mensajes de consola y redacción del README.

**No permitido**: [attached_file:34]

- Delegar el diseño completo de la solución.
- Solicitar código específico que implemente directamente partes del enunciado.
- Incluir código que el equipo no entienda o no pueda modificar durante la sustentación.

El proyecto puede ser penalizado si se detecta código no comprendido por el equipo. [attached_file:34]

---

## Diagramas UML

El repositorio debe incluir diagramas UML en formato **Mermaid**:

- Versión inicial (antes de programar).
- Versión ajustada (después de implementar héroes y objetos mágicos).
- Versión final (después de integrar la Arena). [attached_file:34]

> Los diagramas se deben actualizar para reflejar el diseño real del código.

---

## Bitácora (BITACORA.md)

Cada equipo mantiene un archivo `BITACORA.md` con, al menos, estas columnas: **Fecha**, **Qué decidí**, **Por qué lo hice así**, **Responsable**. [attached_file:34]

- Cada miembro debe aportar **al menos tres entradas** personales.
- El foco es el **razonamiento** y la reflexión, no solo describir tareas. [attached_file:34]

Ejemplo de entrada:

- 8/nov – Crear clase base `Personaje` – Para aplicar herencia y compartir atributos – Juan Camilo. [attached_file:34]

---

## Entregables adicionales

Además del código y este README, el proyecto incluye: [attached_file:34]

- **Video de presentación** (hasta 6 minutos) con:
    - Descripción breve del proyecto.
    - Reflexión metacognitiva individual.
    - Reflexión colaborativa del equipo.
- **Informe de autoevaluación y coevaluación** (PDF individual).
- **BITACORA.md** con reflexión de proceso.
- **Sustentación final** en vivo, realizando cambios sobre el proyecto sin asistencias de IA en el IDE. [attached_file:34]
