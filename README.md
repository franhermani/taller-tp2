# Nombre: Francisco Hermani

# Padrón: 98223

Link GitHub: https://github.com/franhermani/taller-tp2

# Resolución del TP

### Entendimiento del lenguaje C++

Al tratarse de un lenguaje nuevo para mí, decidí comenzar por entender
la sintaxis y las distintas estrategias de codificación de C++.
Para ello, vi nuevamente las diapositivas y las grabaciones de las clases,
y lo fortalecí con investigación online.

Hice principal hincapié en comprender los distintos constructores y las formas
de pasar objetos que ofrece C++, a fin de utilizar adecuadamente cada uno
de ellos según la problemática a resolver.

### Modelado de la solución

Una vez que me sentí cómodo con el nuevo lenguaje, decidí embarcarme en el código
propiamente dicho. Comencé por diagramar mi solución orientada a objetos en mi
cabeza para luego plasmarla en la creación de las distintas clases y sus conexiones
entre ellas.

De este modo, casi sin darme cuenta, ya había llegado a una solución casi completa
del TP, con la cual me sentía cómodo.

### Introducción de Threads, Mutex y Condition Variables

A partir de ese momento, me dediqué a ver nuevamente las clases de Threads, Mutex
y Condition Variables para introducirlos en mi solución.

Decidí desde el primer momento aplicar el patrón Monitor, según el cual se encapsula
tanto el recurso compartido como su mutex. Esto me facilitó **notablemente** el uso
y debug de threads y sus recursos compartidos. De hecho, me encontré solo con
dos situaciones en las cuales el programa caía en un deadlock (por el mismo motivo),
y supe resolverlas en poco tiempo, justamente por el patrón aplicado.

Con respecto a las Condition Variables, fue tal vez lo que más me complicó del TP
en un principio. Comencé por entender el ejemplo mostrado por Ezequiel en clase y
aplicarlo a mi clase Cola con éxito. Luego, trasladé la misma lógica a mi clase
Inventario, aunque con mayor complejidad, como se detallará más adelante.

Cabe destacar que al introducir los threads y mutex, tuve que pensar en detalle
cómo conectar los trabajadores con los recursos, lo cual me llevó a una amplia
reducción de clases que no aportaban nuevo comportamiento y, por ende, eran innecesarias.
Ejemplos de ellas son las clases Agricultor, Leniador, Minero, Cocinero, Carpintero
y Armero, al igual que Carbon, Hierro, Madera y Trigo.

### Refactorización

Como etapa final, me embarqué en un proceso de refactorización. Esto incluyó cosas como:

- Modularización de funciones
- Mejor asignación de responsabilidades
- Uso de constantes en funciones que había pasado por alto
- Inclusión de un archivo *defines.h* para las constantes del enunciado
- Pasaje de las definiciones de todos los métodos a los *.cpp*
- Inhabilitación de constructores y asignaciones por copia en clases
  que había pasado por alto
- Mejor manejo de errores y excepciones
- Lectura del archivo de recursos por línea (y no caracter a caracter)

# Puntos de interés

### Hilo principal

Haciéndole honor al propósito del hilo principal del programa que es,
justamente, orquestar el inicio y fin del resto de los hilos, creé una clase
llamada Orchestrator.

Esta clase centraliza toda la ejecución del programa, y es la "dueña" de
los recursos compartidos. A su vez, se encarga de:
- Procesar y parsear el archivo de trabajadores
- Crear los trabajadores (recolectores y productores)
- Iniciar los trabajadores (*start()*)
- Procesar y parsear el archivo de recursos
- Encolar los recursos en las colas correspondientes
- Cerrar las colas
- Esperar a que finalicen los recolectores (*join()*)
- Cerrar el inventario
- Esperar a que finalicen los productores (*join()*)
- Imprimir por pantalla las estadísticas finales

### Pasaje de objetos

Como punto de partida, decidí inhabilitar los constructores y asignaciones
por copia en las clases que así lo ameritaban. En particular, me refiero a
las clases que representan recursos compartidos y threads.

Luego, tomé la decisión de pasar los recursos (materias primas) con la técnica
*Move Semantics*, ya que intuitivamente así lo pensé en mi cabeza:
1. El recurso nace en un archivo
2. El recurso se pasa a la cola correspondiente
3. El recurso es extraído de la cola y depositado en el inventario
4. El recurso es extraído del inventario y transformado en puntos

Por último, aquellos objetos únicos que son creados y destruidos por el hilo
principal (Orchestrator), decidí pasarlos siempre por referencia, para evitar
copias o movimientos de objetos que no estaban pensados para tal fin y que debían
permanecer únicos durante toda la ejecución del programa. En particular,
me refiero a las tres colas bloqueantes, al inventario y al acumulador de puntos.

### Threads

En este TP, los threads son los trabajadores. Empecé creando una clase Thread con
todos sus métodos tradicionales y, a destacar, un método virtual *run()*, para ser
redefinido por sus clases derivadas según corresponda.

Al principio contaba con una clase Trabajador que heredaba de Thread, y las clases
Recolector y Productor que heredaban de trabajador. Sin embargo, al momento de escribir
estas líneas, me di cuenta que la clase Trabajador carecía de uso y comportamiento propio,
con lo cual decidí eliminarla del medio.

De este modo, tanto la clase Recolector como Productor heredan de Thread y redefinen
el método *run()*.
- En el caso de Recolector, el método *run()* se encarga de desencolar
  un recurso de la cola y depositarlo en el inventario
- En el caso de Productor, el método *run()* se encarga de consumir ciertos
  recursos del inventario y depositarlos en el acumulador de puntos

Es importante destacar que todos los threads inician al mismo tiempo,
pero los recolectores finalizan antes que los productores. Esto es así ya que,
justamente, la finalización de los recolectores es la señal de que no hay más
recursos para depositar en el inventario, momento en el cual se cierra el mismo
y se avisa a los productores, para que no sigan buscando recursos que nunca van a llegar.

### Mutex

Como se mencionó en la sección anterior, apliqué el patrón Monitor, según el cual
encapsulé los Mutex en las clases que representan recursos compartidos. Se trata
de la clase Cola, Inventario y AcumuladorPuntos. Fuera de estas clases no se hizo uso
de ningún mutex.

Inicialmente, caí en la tentación de colocar un mutex en cada método de las clases
mencionadas, pero esto me ocasionó dos deadlocks. Así, me detuve a pensar cuáles eran
realmente las secciones críticas, y dejé solo los mutex necesarios. Acto seguido,
ambos deadlocks desaparecieron.

Las secciones críticas de la Cola son:
- Encolar un recurso
- Desencolar un recurso
- Obtener su largo
- Cerrarse

Las secciones críticas del Inventario son:
- Depositar un recurso (esto es, encolarlo en la Cola correspondiente)
- Consumir un conjunto de recursos (esto es, desencolar recursos de
  las Colas correspondientes)
- Cerrarse

Las secciones críticas del AcumuladorPuntos son:
- Sumar puntos
- Obtener puntos

### Condition Variables

Clase Cola:
- Cada vez que un thread llama al método *desencolar()*, entra en un while
  que solo se rompe si la cola tiene algún elemento. Si la cola está vacía,
  el thread ingresa en estado *wait* hasta que se inserte un nuevo elemento
  o bien se cierre la cola.
- Cada vez que se encola un nuevo elemento, se notifica a todos los threads
  que estaban en estado *wait* mediante *notify_all()*
- Cuando se cierra la cola, se notifica a todos los threads
  que estaban en estado *wait* mediante *notify_all()*

Clase Inventario:
- Cada vez que un thread llama al método *consumirRecursos()*, entra en un while
  que solo se rompe si todos los recursos solicitados están disponibles.
  Para ello, se llama al método *armarConjunto()* que realiza un chequeo de la
  disponibilidad, y solo en caso de tener suficiente procede a desencolar
  los recursos. Si no hay suficientes recursos, el thread ingresa en estado *wait*
  hasta que se inserte un nuevo elemento o bien se cierre el inventario.
- Cada vez que se encola un nuevo elemento, se notifica a todos los threads
  que estaban en estado *wait* mediante *notify_all()*
- Cuando se cierra el inventario, se notifica a todos los threads
  que estaban en estado *wait* mediante *notify_all()* 

### Modelado del inventario

El inventario lo modelé como un conjunto de cuatro colas bloqueantes,
una por cada recurso (carbón, hierro, madera y trigo).
Esto facilita el consumo de recursos por parte de los productores, ya que
se llama al método desencolar en cada cola según la cantidad solicitada,
sin necesidad de estar buscando todos los recursos en una misma cola.

# Aclaraciones

- Al procesar el archivo de trabajadores, la clase Orchestrator valida
  el formato del archivo, que los trabajadores especificados sean los de la consigna
  y que las cantidades especificadas sean numeros enteros positivos.
- Al leer el archivo de recursos no se validan los caracteres. Simplemente
  se hace caso omiso a aquellos caracteres que no pertenecen al enunciado.
  Esto es así porque, al momento de procesar el archivo, los threads ya están corriendo y,
  en particular, los recolectores ya están a la espera de que se encolen los recursos.
  Así, cada vez que se lee un caracter del archivo, se lo encola y un recolector ya puede
  tomarlo. De este modo, no consideré conveniente frenar la ejecución en caso de que
  el archivo contenga un caracter no válido.
