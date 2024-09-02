#ifndef FUNCIONES_GRUPO_H_INCLUDED
#define FUNCIONES_GRUPO_H_INCLUDED
/*
Aquí deben hacer los includes de sus archivos individuales, por ejemplo:
#include "funciones_rufino.h"
 */
#include "funciones_fuente.h"
#include "funciones_fernandes.h"
#include "funciones_wu.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void matrizDestruir(void** mat,int filas);
void** matrizCrear(size_t tamElem, int filas, int columnas);
void paddingInicial(FILE* pf, int comienzoImagen);
void paddingLinea(FILE* pf, int cantidad);
int solucion(int argc, char* argv[]);
#endif // FUNCIONES_GRUPO_H_INCLUDED
