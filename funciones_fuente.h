#ifndef FUNCIONES_FUENTE_H_INCLUDED
#define FUNCIONES_FUENTE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "estructuras.h"

#define TIPO_BMP 0x4D42
#define TAM_HEADER 54

#define BLUE 0
#define RED 1
#define GREEN 2
#define VALOR_MEDIO_COLOR 127
#define VALOR_MIN_COLOR_24_BITS_PROF 0
#define VALOR_MAX_COLOR_24_BITS_PROF 255


#define ARCH_NO_ENCONTRADO 3
#define FORMATO_INCORRECTO 4

/*aumentarContraste, espejarVertical, concatenarHorizontal, tonalidadRojo, achicar*/

void** matrizCrear(size_t tamElem, int filas, int columnas);
void matrizDestruir(void** mat,int filas);

void paddingInicial(FILE* pf, int comienzoImagen);
void paddingLinea(FILE* pf, int cantidad);
void aplicarPorcentaje(unsigned char *color, float porcentaje, unsigned char limite);
void aplicarPorcentajeMin(unsigned char *color, float porcentaje, unsigned char limite);

void aumentarContraste(t_pixel *pixel, unsigned char porcentaje);
#endif // FUNCIONES_FUENTE_H_INCLUDED
