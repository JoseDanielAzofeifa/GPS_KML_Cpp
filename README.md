#“Manual de Usuario II Proyecto” #
##Instituto Tecnológico de Costa Rica ##
###ESCUELA DE INGENIERIA EN COMPUTACION ###
###Estructuras de datos ###

**Profesor:** 

Msc.Armando Arce

**Estudiantes:** 

Jose Daniel Azofeifa Ugalde

Albin Ramírez Cubillo


## • Introducción##
Esta aplicación ha sido desarrollada para ver diversos gráficos relacionados con con el formato kml de google earth, además de poder ver los diversos mapas podrá realizar zoom y moverse por todo el mapa y realizar búsquedas de rutas más cortas de una forma amigable con el usuario.

## • Descripción del problema##
Con esta aplicación se podrán desplegar diversos gráficos de formato kml de google earth, esta aplicación se busca la ruta más corta entre calles para llegar más rápido al destino deseado, esto gracias al camino más corto desarrolado con el algoritmo Floyd . 

## • Explicación de clases y rutinas principales##
Para esta aplicación se utilizo una clase que llamamos MyCanvas la cual es la encargada de lo que se refiere a dibujo. Además de esta clase se uso la clase del tinyxml2 la cual se debe usar para las operaciones de lectura al archivo kml, esta clase es perteneciente a la librería tinyxml2. También creamos varios métodos, el principal es el main en el cual se inicializa el programa. Luego tenemos los métodos encargados de modificar el tamaño del dibujo entre los que están: 

* El método reset el cual es el encargado de restablecer el tamaño del dibujo.

* El método zoomOut el cual es el encargado de reducir el tamaño del dibujo.

* El método zoomIn el cual es el encargado de aumentar el tamaño del dibujo.

También tenemos los métodos encargados de los pan o desplazamientos entre los que están:

* El método down el cual es el encargado de mover el dibujo hacia abajo.

* El método up el cual es el encargado de mover el dibujo hacia arriba.

* El método left el cual es el encargado de mover el dibujo hacia la izquierda.

* El método right el cual es el encargado de mover el dibujo hacia la derecha.

Por otro lado están los métodos para indicar de que punto a que punto desea ir para así averiguar la ruta más corta, los métodos encargados de esto son gps_ window y gps_cb, luego estos utilizan la clase floyd para averiguar el camino más corto y luego se dibuja en la pantalla de color rojo.

Unos de los métodos más importantes son open_ window y read_cb las cuales son para que el usuario pueda abrir el archivo kml, luego de digitar la dirección del archivo y oprimir open se usara el método leer el cual es el encargado de conseguir las coordenadas contenidas en el kml, también se usara el método sacarcoor el cual guarda las coordenadas en los vectores para poder ser utilizados.


##• Descripción del formato de archivos##
En esta aplicación se lee el archivo kml con el método llamado leer el cual identifica si son coordenadas simples o son puntos de una figura luego utiliza la función sacarcoor la cual guarda las coordenadas en los respectivos vectores. 

## • Corridas de ejemplo##
Esta aplicación se debe compilar utilizando Dev-cpp 4.9.9.2 además de utilizar la librería FLTK 1.1.7 previamente agregada al Dev-cpp y la libreria Tinyxml2.

Se debe de ejecutar con el Dev-cpp o con  ProyectoDatos.exe.

A continuación se explicar como utilizar la aplicación: 

Primero deberá abrir ProyectoDatos.exe

Como segundo paso deberá oprimir el botón de open y se desplegara la siguiente pantalla en la cual deberá escribir la dirección en la que se encuentra el archivo kml.

Luego de oprimir open, si la dirección es correcta se desplegara el siguiente mensaje:

![imgopen][open]
[open](http://sphotos-c.ak.fbcdn.net/hphotos-ak-ash4/391763_440567555999640_623212238_n.jpg)

Y seguidamente se dibujara el grafico.

![imggraf][grafico]
[grafico](http://sphotos-f.ak.fbcdn.net/hphotos-ak-prn1/44513_440567449332984_2125658270_n.jpg)

Se podrá realizar zoom in

![imgzoomin][zoomin]
[zoomin](http://sphotos-d.ak.fbcdn.net/hphotos-ak-ash3/27999_440567752666287_305026724_n.jpg)

Además de zoom out

![imgzoomout][zoomout]
[zoomout](http://sphotos-a.ak.fbcdn.net/hphotos-ak-snc6/249281_440567762666286_1314752359_n.jpg)

Tambien podrá restablecer el tamaño original

![imgres][reset]
[reset](http://sphotos-e.ak.fbcdn.net/hphotos-ak-ash3/21789_440567579332971_1514137842_n.jpg)

Por otro lado podrá desplazarse por lo largo del mapa gracias a los botones up, down, left, right

##UP
![imgdesp][desp]
[desp](http://sphotos-f.ak.fbcdn.net/hphotos-ak-prn1/32403_440567665999629_253429412_n.jpg)

##DOWN
![imgdesp][desp]
[desp](http://sphotos-c.ak.fbcdn.net/hphotos-ak-prn1/560681_440567252666337_98111625_n.jpg)

##LEFT
![imgdesp][desp]
[desp](http://sphotos-d.ak.fbcdn.net/hphotos-ak-prn1/32427_440567502666312_1998601113_n.jpg)

##RIGHT
![imgdesp][desp]
[desp](http://sphotos-b.ak.fbcdn.net/hphotos-ak-ash3/527322_440567602666302_28661260_n.jpg)

Además podrá averiguar la ruta más corta de un punto a otro con el boton gps, el cual abrira una venta en la que debe digitar las coordenadas y oprimir go

![imggps][gps]
[gps](http://sphotos-b.ak.fbcdn.net/hphotos-ak-ash3/523548_440567279333001_671418055_n.jpg)


luego se mostrara en pantalla de color rojo la ruta más corta entre los puntos indicados anteriormente

![imggps][gps2]
[gps2](http://sphotos-h.ak.fbcdn.net/hphotos-ak-snc6/253151_440567429332986_486757602_n.jpg)


## • Análisis de resultados##

Por razones de tiempo no hemos podido implementar de la mejor manera el algoritmo para averiguar el camino más corto.


## • Conclusiones
Gracias a este proyecto hemos aprendido a trabajar con archivos de tipo kmz, kml, xml, entre otros formatos similares.Además hemos aumentado nuestros conocimientos sobre el lenguaje de programación c++ y la libreria FLTK. Por otro lado hemos ampliado nuestros conocimientos sobre el método del camino más corto conocido como algoritmo de Floyd.

La principal limitación que se nos presento fue el poco tiempo para desarrollar la aplicación.  

