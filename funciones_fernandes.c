#include "funciones_fernandes.h"

void reducirContraste(t_pixel *pixel, unsigned char porcentaje)
{
    unsigned char promedio = (pixel->color[BLUE] + pixel->color[RED] + pixel->color[GREEN])/3;

    if(promedio < VALOR_MEDIO_COLOR)
    {
        aumentarPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MEDIO_COLOR);
        aumentarPorcentaje(&pixel->color[RED], porcentaje, VALOR_MEDIO_COLOR);
        aumentarPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MEDIO_COLOR);

    }
    else
    {
        disminuirPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MEDIO_COLOR);
        disminuirPorcentaje(&pixel->color[RED], porcentaje, VALOR_MEDIO_COLOR);
        disminuirPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MEDIO_COLOR);

    }
}

void tonalidadVerde(t_pixel *pixel, unsigned char porcentaje)
{
    aumentarPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MAX_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[RED], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);
    disminuirPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MIN_COLOR_24_BITS_PROF);

}

int espejarHorizontal()
{

    FILE *pf = fopen("unlam.bmp", "rb");
    t_header encabezado;
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
    fseek(pf, encabezado.comienzoImagen, SEEK_SET);

    FILE *pf2 = fopen("VANGUARDIA_espejar-horizontal_unlam.bmp", "wb");

    if(!pf2)
    {
        puts("Error al intentar abrir el archivo.");
        fclose(pf);
        return ARCH_NO_ENCONTRADO;
    }

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);
    fwrite(&encabezado,sizeof(t_header), 1, pf2);
    fseek(pf2, encabezado.comienzoImagen, SEEK_SET);

    t_pixel** matEspejadaH = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = encabezado.ancho - 1; j >= 0; j--)
            fread(&matEspejadaH[i][j], sizeof(t_pixel), 1, pf);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < encabezado.ancho; j++)
            fwrite(&matEspejadaH[i][j], sizeof(t_pixel), 1, pf2);

    matrizDestruir((void**)matEspejadaH, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);

    return TODO_OK;
}

int concatenarVertical()
{
        FILE *pf = fopen("unlam.bmp", "rb");
    t_header encabezado, encabezado2, encabezadoNuevo;
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

    FILE *pf2 = fopen("unlam2.bmp", "rb");

    if(!pf2)
    {
        puts("Error al intentar abrir el archivo.");
        fclose(pf);
        return ARCH_NO_ENCONTRADO;
    }

    fread(&tipoFichero, sizeof(unsigned short), 1, pf2);

    if(tipoFichero != TIPO_BMP)
    {
        fclose(pf);
        fclose(pf2);
        return FORMATO_INCORRECTO;
    }

    fread(&encabezado2,sizeof(t_header), 1, pf2);

    FILE *pf3 = fopen("VANGUARDIA_concatenar-vertical_unlam.bmp", "wb");
    if(!pf3)
    {
        puts("Error al crear archivo.");
        fclose(pf);
        fclose(pf2);
        return ERROR_CREAR_ARCHIVO;
    }

    encabezadoNuevo = encabezado;
    encabezadoNuevo.alto += encabezado2.alto;
    if(encabezado2.ancho > encabezado.ancho)
        encabezadoNuevo.ancho = encabezado2.ancho;
    encabezadoNuevo.tamImagen += encabezado2.tamImagen;
    encabezadoNuevo.tamArchivo += encabezado2.tamArchivo;

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf3);
    fwrite(&encabezadoNuevo, sizeof(t_header), 1, pf3);

    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
    fseek(pf2, encabezado2.comienzoImagen, SEEK_SET);
    fseek(pf3, encabezadoNuevo.comienzoImagen, SEEK_SET);

    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado2.alto, (size_t)encabezado2.ancho);

    char color [3]= {0,0,255};

    for(int i = 0; i < encabezado2.alto; i++)
        fread(matImgOrig[i], sizeof(t_pixel), encabezado2.ancho, pf2);

    for(int i = 0; i < encabezado2.alto; i++)
    {
        fwrite(matImgOrig[i], sizeof(t_pixel), encabezado2.ancho, pf3);
        if(encabezado2.ancho < encabezado.ancho)
        {
            for(int j=0; j<(encabezado.ancho - encabezado2.ancho); j++)
                fwrite(&color, sizeof(t_pixel), 1, pf3);
        }
    }

    matrizDestruir((void**)matImgOrig, (size_t)encabezado2.alto);

    matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);

    for(int i = 0; i < encabezado.alto; i++)
            fread(matImgOrig[i], sizeof(t_pixel), encabezado.ancho, pf);

    for(int i = 0; i < encabezado.alto; i++)
    {
            fwrite(matImgOrig[i], sizeof(t_pixel), encabezado.ancho, pf3);
        if(encabezado.ancho < encabezado2.ancho)
        {
            for(int j=0; j<(encabezado2.ancho - encabezado.ancho); j++)
                fwrite(&color, sizeof(t_pixel), 1, pf3);
        }
    }
    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);
    fclose(pf3);

    return TODO_OK;
}

int rotarDerecha()
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

    FILE *pf2 = fopen("VANGUARDIA_rotar-derecha_unlam.bmp", "wb");

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

    for(int i = encabezado.ancho - 1; i >= 0; i--)
        for(int j = 0; j < encabezado.alto; j++)
            fwrite(&matImgOrig[j][i], sizeof(t_pixel), 1, pf2);

    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);

    return TODO_OK;
}
