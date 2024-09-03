#ifndef FUNCIONES_FUENTE_H_INCLUDED
#define FUNCIONES_FUENTE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "estructuras.h"

#define TIPO_BMP 0x4D42
#define RED 2
#define GREEN 1
#define BLUE 0
#define TAM_HEADER 54
#define ARCH_NO_ENCONTRADO 3
#define FORMATO_INCORRECTO 4

/*aumentarContraste, espejarVertical, concatenarHorizontal, tonalidadRojo, achicar*/

void** matrizCrear(size_t tamElem, int filas, int columnas);
void matrizDestruir(void** mat,int filas);
void paddingInicial(FILE* pf, int comienzoImagen);
void paddingLinea(FILE* pf, int cantidad);

int tonalidadRoja(FILE* pf, t_header* encabezado);

#endif // FUNCIONES_FUENTE_H_INCLUDED
