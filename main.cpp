#include "miniwin.h"	//Incluimos la libreria miniwin
#include <stdlib.h>		//Incluimos la libreria estandar para poder hacer uso de la funcion rand() usada mas adelante
using namespace miniwin;

int main() {
	vredimensiona(600, 400);	//Genera una ventana de 600px por 400px
	texto(50, 10, "Aprendiendo a usar miniwin");	//Dibuja el texto "Aprendiendo a usar miniwin" en la posicion 50, 10
	
	color(ROJO);	//Establecemos el color en ROJO
	linea(0, 0, 600, 400);	//Dibuja una linea roja que va de 0, 0 a 600, 400
	
	//color(AMARILLO);
	//circulo_lleno(300, 200, 50);
	
	color(VERDE);	//Establecemos el color en VERDE
	rectangulo_lleno(50, 50, 100, 60);	//Dibuja un rectangulo relleno en la posicion 50, 50 y sus lados miden 100 x 60
	
	for (int i = 0; i < 400; i++) {
		punto(i, i);	//Cada iteracion dibuja un punto en la posicion i, i
		refresca();		//Dibuja la posicion del punto en la iteracion
		espera(1);		//Espera un milisegundo para dar un efecto de animacion
	}
	
	for (int r = rand()%255 , g = rand()%255, b = rand()%255 ; ; r++, g++, b++) {
		if (r == 255 || g == 255 || b == 255) {
			r = rand()%255;
			g = rand()%255;
			b = rand()%255;
		}
		color_rgb(r,g,b);	//Generamos un color personalizado que cada iteracion ira cambiando segun los iteradores del for
		circulo_lleno(300, 200, 50);	//Dibuajos un circulo rrelleno en la posicion 300, 200 con un radio de 50
		refresca();		//Regrescamos para dibujar los cambios de color del circulo
		espera(1);		//Espera un milisegundo para ver la animacion de cambio de color
		
		int t = tecla();	//Definimos una variable para escuchar el presionado de teclas
		if ( t == ESCAPE) {	//Si la tecla presionada es igual a ESCAPE entonces se terminara el bucle For
			break;
		}
	}
	
	refresca();		//Dibujamos todos los elementos que hemos declarado
	return 0;
}
