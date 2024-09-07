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

void aumentarPorcentaje(unsigned char *color, float porcentaje, unsigned char limite)
{
    int aux = *color;
    aux += aux * porcentaje / 100;
    if(aux > limite)
    {
        *color = limite;
    }
    else
    {
        *color = aux;
    }
}

void disminuirPorcentaje(unsigned char *color, float porcentaje, unsigned char limite)
{
    int aux = *color;
    aux -= aux * porcentaje / 100;
    if(aux < limite)
    {
        *color = limite;
    }
    else
    {
        *color = aux;
    }
}

void aumentarContraste(t_pixel *pixel, unsigned char porcentaje)
{
    unsigned char promedio = (pixel->color[BLUE] + pixel->color[RED] + pixel->color[GREEN])/3;

    if(promedio > VALOR_MEDIO_COLOR)
    {
        aumentarPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);
        aumentarPorcentaje(&pixel->color[RED], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);
        aumentarPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);

    }
    else
    {
        disminuirPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
        disminuirPorcentaje(&pixel->color[RED], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
        disminuirPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
    }

}

void tonalidadRoja(t_pixel *pixel, unsigned char porcentaje)
{
    aumentarPorcentaje(&pixel->color[RED], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);

}
