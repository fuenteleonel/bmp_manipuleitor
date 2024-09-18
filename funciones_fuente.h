#ifndef FUNCIONES_FUENTE_H_INCLUDED
#define FUNCIONES_FUENTE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TIPO_BMP 0x4D42
#define TAM_HEADER 54

#define BLUE 0
#define GREEN 1
#define RED 2
#define VALOR_MEDIO_COLOR 127
#define VALOR_MIN_COLOR_24_BITS_PROF 0
#define VALOR_MAX_COLOR_24_BITS_PROF 255

#define TODO_OK 0
#define ARCH_NO_ENCONTRADO 3
#define FORMATO_INCORRECTO 4
#define ERROR_CREAR_ARCHIVO 5

typedef struct
{
    unsigned char color[3];
} t_pixel;

typedef struct
{
    unsigned int tamArchivo;
    unsigned int reservado;
    unsigned int comienzoImagen;   // Por eso dejo espacio para ambas cosas
    unsigned int tamEncabezado;    // El tamaño del encabezado no siempre coincide con el comienzo de la imagen
    unsigned int ancho;
    unsigned int alto;
    unsigned short numPlanos;
    unsigned short profundidad;
    unsigned int compresion;
    unsigned int tamImagen;
    unsigned int resolH;
    unsigned int resolV;
    unsigned int tamColor;
    unsigned int cantColores;
} t_header;


void** matrizCrear(size_t tamElem, size_t filas, size_t columnas);
void matrizDestruir(void** mat, size_t filas);

void paddingInicial(FILE* pf, int comienzoImagen);
void paddingLinea(FILE* pf, int cantidad);

void aumentarPorcentaje(unsigned char *color, float porcentaje, unsigned char limite);
void disminuirPorcentaje(unsigned char *color, float porcentaje, unsigned char limite);

void leerArgumentos(int argc, char* argv[], bool* argNegativo, bool* argEscalaDeGrises,
                    bool* argAumentarContraste, bool* argReducirContraste,
                    bool* argTonalidadAzul, bool* argTonalidadVerde, bool* argTonalidadRoja,
                    bool* argRotarDerecha, bool* argRotarIzquierda,
                    bool* argComodin, bool* argConcatenarHorizontal, bool* argConcatenarVertical,
                    bool* argEspejarVertical, bool* argEspejarHorizontal,
                    char** nombreArchivo, char** nombreArchivo2,
                    unsigned char* porcAumCont, unsigned char* porcRedCont, unsigned char* porcTonAzul,
                    unsigned char* porcTonVerde, unsigned char* porcTonRoja);

int funcionBasica(void (*filtro)(t_pixel* pixel, unsigned char porcentaje), unsigned char porcentaje, char** nombreArchivo, char* nombreFiltro);

void aumentarContraste(t_pixel *pixel, unsigned char porcentaje);
void tonalidadRoja(t_pixel *pixel, unsigned char porcentaje);
int espejarVertical(char** nombreArchivo);
int concatenarHorizontal(char** nombreArchivo, char** nombreArchivo2);
//void achicar() No se realizo esta función debido a que en este trabajo trabajamos con memoria dinamica. Entonces decidimos que esta funcion era una de las que no haríamos

#endif // FUNCIONES_FUENTE_H_INCLUDED
