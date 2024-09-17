#include "funciones_wu.h"

void tonalidadAzul(t_pixel *pixel, unsigned char porcentaje)
{
    aumentarPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[RED], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);

}

void escalaDeGrises(t_pixel *pixel)
{
    unsigned char promedio = (pixel->color[BLUE] + pixel->color[RED] + pixel->color[GREEN])/3;

    pixel->color[BLUE] = promedio;
    pixel->color[GREEN] = promedio;
    pixel->color[RED] = promedio;
}

void negativo(t_pixel *pixel)
{
    pixel->color[BLUE]= VALOR_MAX_COLOR_24_BITS_PROF - pixel->color[BLUE];
    pixel->color[RED]= VALOR_MAX_COLOR_24_BITS_PROF - pixel->color[RED];
    pixel->color[GREEN]= VALOR_MAX_COLOR_24_BITS_PROF - pixel->color[GREEN];
}

int rotarIzquierda()
{

    FILE *pf = fopen("unlam.bmp", "rb");
    t_header encabezado, encabezadoNuevo;
    unsigned short tipoFichero;

    if(!pf)
    {
        puts("Error al intentar abrir el archivo.");
        return ARCH_NO_ENCONTRADO;
    }

    fread(&tipoFichero, sizeof(unsigned short), 1, pf);

    if(tipoFichero != TIPO_BMP)
    {
        fclose(pf);
        return FORMATO_INCORRECTO;
    }

    fread(&encabezado,sizeof(t_header), 1, pf);
    encabezadoNuevo = encabezado;

    FILE *pf2 = fopen("VANGUARDIA_rotar-izquierda_unlam.bmp", "wb");

    if(!pf2)
    {
        puts("Error al intentar abrir el archivo.");
        fclose(pf);
        return ARCH_NO_ENCONTRADO;
    }

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);

    encabezadoNuevo.alto = encabezado.ancho;
    encabezadoNuevo.ancho = encabezado.alto;

    fwrite(&encabezadoNuevo,sizeof(t_header), 1, pf2);

    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
    fseek(pf2, encabezadoNuevo.comienzoImagen, SEEK_SET);

    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < encabezado.ancho; j++)
            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);

    for(int i = 0; i < encabezado.ancho; i++)
        for(int j = encabezado.alto - 1; j >= 0; j--)
            fwrite(&matImgOrig[j][i], sizeof(t_pixel), 1, pf2);

    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);

    return TODO_OK;
}
