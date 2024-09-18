#ifndef FUNCIONES_WU_H_INCLUDED
#define FUNCIONES_WU_H_INCLUDED

#include "funciones_fuente.h"



void tonalidadAzul(t_pixel *pixel, unsigned char porcentaje);
void escalaDeGrises(t_pixel *pixel, unsigned char porcentaje);
void negativo(t_pixel *pixel, unsigned char porcentaje);
int rotarIzquierda(char** nombreArchivo);

#endif // FUNCIONES_WU_H_INCLUDED
