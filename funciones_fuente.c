#include "funciones_fuente.h"

void** matrizCrear(size_t tamElem, int filas, int columnas)
{
    void** mat = malloc(sizeof(void*)*filas);
    if(!mat)
        return NULL;

    void** ult = mat + filas - 1;
    for(void** i = mat; i <= ult; i++)
    {
        *i = malloc(tamElem * columnas);
        if(!*i)
        {
            matrizDestruir(mat, i-mat);
            return NULL;
        }
    }
    return mat;
}

void matrizDestruir(void** mat,int filas)
{
    void** ult = mat + filas - 1;
    for(void** i= mat; i<= ult;i++)
        free(*i);
    free(mat);
}

void paddingInicial(FILE* pf, int comienzoImagen) //Escribe bytes de padding en un puntero desde el final del header
{                                                 //el comienzo de la imagen
    char zero = '0';
    fwrite(&zero, sizeof(char), comienzoImagen-TAM_HEADER, pf);
}

void paddingLinea(FILE* pf, int cantidad)
{
    char zero = '0';
    fwrite(&zero, sizeof(char), cantidad, pf);
}

