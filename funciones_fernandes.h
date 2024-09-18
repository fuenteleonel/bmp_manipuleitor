#ifndef FUNCIONES_FERNANDES_H_INCLUDED
#define FUNCIONES_FERNANDES_H_INCLUDED

#include "funciones_fuente.h"

void reducirContraste(t_pixel *pixel, unsigned char porcentaje);
void tonalidadVerde(t_pixel *pixel, unsigned char porcentaje);
int espejarHorizontal(char** nombreArchivo);
int concatenarVertical(char** nombreArchivo, char** nombreArchivo2);
int rotarDerecha(char** nombreArchivo);


#endif // FUNCIONES_FERNANDES_H_INCLUDED
