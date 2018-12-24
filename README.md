# interchange-simulator
Rail freight interchange simulator using list data structure with C++ language.

## Objetivo
El objetivo de esta práctica es simular el funcionamiento de un centro de intercambio de vagones entre trenes de mercancías. El centro se sitúa en Madrid, como centro neurálgico de la red de ferrocarril española y facilita el correcto envío de mercancías entre distintas estaciones de dicha red.

## Implementación
En la presente práctica se debe modelar el comportamiento del sistema de intercambio de acuerdo a las siguientes normas:

* Se considerará la existencia de cinco trenes circulando según los datos de esta tabla:

   | Nº de tren  | Orígen  | Destino  |
   |---|---|---|
   | 123  | Sevilla  | Valladolid  |
   | 456  | Zamora  | Zaragoza  |
   | 224  | Badajoz  | Burgos  |
   | 801  | Cuenca  | Orense  |
   | 652  | Albacete  | Bilbao  |


* Se modelará cada uno de los trenes utilizando una lista dinámica.
* El centro de intercambio de vagones de mercancías operará con esas listas para realizar las operaciones necesarias y lograr el correcto trasvase de vagones.
* Cada tren constará de una máquina cuyo código de identificación será el mismo que el de la línea que cubre.
* El código de identificación de los vagones se generará aleatoriamente, siendo un número de cuatro cifras. El código de identificación será único para cada vagón.
* El número de vagones de cada tren se elegirá aleatoriamente, siendo un número entre 2 y 5, ambos incluidos.
* El origen y destino de cada uno de los vagones, según la tabla anterior, se asignarán también de forma aleatoria.
* El tipo de carga de cada vagón queda a criterio del alumno, pudiendo asignarse de forma aleatoria si lo estima necesario.
* El sistema debe permitir la monitorización de la composición de cada uno de los trenes antes y después de su paso por el centro de intercambio de vagones de mercancías.
* Se valorará positivamente la implementación de cualquier mejora en el programa que permita un mejor seguimiento de los vagones de mercancías en su trayecto desde la
estación de origen a la estación de destino.