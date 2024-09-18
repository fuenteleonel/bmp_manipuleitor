#ifndef FUNCIONES_WU_H_INCLUDED
#define FUNCIONES_WU_H_INCLUDED

#include "funciones_fuente.h"

void tonalidadAzul(t_pixel *pixel, unsigned char porcentaje);
void escalaDeGrises(t_pixel *pixel, unsigned char porcentaje);
void negativo(t_pixel *pixel, unsigned char porcentaje);
void comodin(t_pixel *pixel, unsigned char porcentaje);
int rotarIzquierda(char** nombreArchivo);
//void recortar() No se realizo esta función debido a que en este trabajo trabajamos con memoria dinamica. Entonces decidimos que esta funcion era una de las que no haríamos

#endif // FUNCIONES_WU_H_INCLUDED
