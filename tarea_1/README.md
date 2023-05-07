## Instrucciones para ejecutar la tarea 1 de GPU

1. Crear la carpeta build `mkdir build`
2. Ejecutar el comando `cmake ..` dentro de la carpeta build
3. Ejecutar el comando `make` dentro de la carpeta build

Con estos pasos se generarán 2 cosas:
- El ejecutable `tarea_1` dentro de la carpeta `build` que se puede ejecutar con el comando `./tarea_1` y que contiene una pequeña aplicacion utilizando las clases `Point`, `Vector` y `Polygon`.
- También se generará una carpeta llamada `test` dentro de build, la cual contiene el ejecutable `TareaTests` para la ejecución de los tests unitarios de las tres clases implementadas.

Para ejecutar los test unitarios se debe ejecutar el comando `./TareaTests` dentro de la carpeta `build/test`. Cada uno de los test unitarios se encuetran en la carpeta test fuera de build.
