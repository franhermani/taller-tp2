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

### Introducción de Threads y Mutex

A partir de ese momento, me dediqué a ver nuevamente las clases de Threads y Mutex
para introducirlos en mi solución.

Decidí desde el primer momento aplicar el patrón Monitor, según el cual se encapsula
tanto el recurso compartido como su mutex. Esto me facilitó **notablemente** el uso
y debug de threads y sus recursos compartidos. De hecho, me encontré solo con
dos situaciones en las cuales el programa caía en un deadlock (por el mismo motivo),
y supe resolverlas en poco tiempo, justamente por el patrón aplicado.

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

# Puntos de interés

- Al leer el archivo de recursos no se validan los caracteres. Simplemente
  se hace caso omiso a aquellos caracteres que no pertenecen al enunciado.
  Esto es asi porque los threads ya están corriendo en este punto y a medida
  que se encola un recurso los threads lo van buscando, no se puede frenar la
  ejecución en este punto
- Los recursos los paso por movimiento
- Las colas, el inventario y el acumulador de puntos los paso por referencia.
  A su vez, inhabilité los constructores y asignadores por copia en todas las clases


# Aclaraciones

