# Nombre: Francisco Hermani

# Padrón: 98223

Link GitHub: https://github.com/franhermani/taller-tp2

# Resolución del TP


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

