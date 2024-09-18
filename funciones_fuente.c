#include "funciones_fuente.h"

void** matrizCrear(size_t tamElem, size_t filas, size_t columnas)
{
    void** mat = (void**)malloc(sizeof(void*)* filas);
    if(!mat)
        return NULL;

    void** ult = mat + filas - 1;
    for(void** i = mat; i <= ult; i++)
    {
        *i = (void**)malloc(tamElem * columnas);
        if(!*i)
        {
            matrizDestruir(mat, (size_t)(i-mat));
            return NULL;
        }
    }
    return mat;
}

void matrizDestruir(void** mat, size_t filas)
{
    void** ult = mat + filas - 1;
    for(void** i= mat; i<= ult; i++)
        free(*i);
    free(mat);
}

void paddingInicial(FILE* pf, int comienzoImagen) ///Escribe bytes de padding en un puntero desde el final del header hasta el comienzo de la imagen
{
    char zero = '0';
    fwrite(&zero, sizeof(char), comienzoImagen-TAM_HEADER, pf);
}

void paddingLinea(FILE* pf, int cantidad) /// Escribe bytes de padding para hacer que una linea sea divisible por 4
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

//int achicar()
//{
//    FILE *pf = fopen("unlam.bmp", "rb");
//    t_header encabezado, encabezadoNuevo;
//    unsigned short tipoFichero;
//
//    if(!pf)
//    {
//        puts("Error al intentar abrir el archivo.");
//        return ARCH_NO_ENCONTRADO;
//    }
//
//    fread(&tipoFichero, sizeof(unsigned short), 1, pf);
//
//    if(tipoFichero != TIPO_BMP)
//    {
//        fclose(pf);
//        return FORMATO_INCORRECTO;
//    }
//
//    fread(&encabezado,sizeof(t_header), 1, pf);
//    encabezadoNuevo = encabezado;
//    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
//
//    FILE *pf2 = fopen("VANGUARDIA_achicar_unlam.bmp", "wb");
//
//    if(!pf2)
//    {
//        puts("Error al intentar abrir el archivo.");
//        fclose(pf);
//        return ARCH_NO_ENCONTRADO;
//    }
//
//    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);
//
//    encabezadoNuevo.alto /= 2;
//    encabezadoNuevo.ancho /= 2 ;
//    encabezadoNuevo.tamImagen = encabezadoNuevo.alto * encabezadoNuevo.ancho * 3;
//    encabezadoNuevo.tamArchivo = encabezadoNuevo.tamImagen + TAM_HEADER;
//
//    fwrite(&encabezadoNuevo,sizeof(t_header), 1, pf2);
//
//    fseek(pf2, encabezadoNuevo.comienzoImagen, SEEK_SET);
//
//    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < encabezado.ancho; j++)
//            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);
//
//    for(int i = 0; i < encabezado.alto; i+=2)
//        for(int j = 0; j < encabezado.ancho; j+=2)
//            fwrite(&matImgOrig[i][j], sizeof(t_pixel), 1, pf2);
//
//    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
//    fclose(pf);
//    fclose(pf2);
//
//    return TODO_OK;
//}

int espejarVertical(char** nombreArchivo)
{

    FILE *pf = fopen(*nombreArchivo, "rb");
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

    char nombre[255] = "VANGUARDIA_espejar-vertical_";
    const char* foto = *nombreArchivo;
    strcat(nombre, foto);

    FILE *pf2 = fopen(nombre, "wb");

    if(!pf2)
    {
        puts("Error al intentar abrir el archivo.");
        fclose(pf);
        return ARCH_NO_ENCONTRADO;
    }

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);
    fwrite(&encabezado,sizeof(t_header), 1, pf2);
    fseek(pf2, encabezado.comienzoImagen, SEEK_SET);

    t_pixel** matEspejadaV = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);

    for(int i = encabezado.alto - 1; i >= 0; i--)
        for(int j = 0; j < encabezado.ancho; j++)
            fread(&matEspejadaV[i][j], sizeof(t_pixel), 1, pf);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < encabezado.ancho; j++)
            fwrite(&matEspejadaV[i][j], sizeof(t_pixel), 1, pf2);

    matrizDestruir((void**)matEspejadaV, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);

    return TODO_OK;
}

int concatenarHorizontal(char** nombreArchivo, char** nombreArchivo2)
{
    FILE *pf = fopen(*nombreArchivo, "rb");
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

    FILE *pf2 = fopen(*nombreArchivo2, "rb");

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

    char nombre[255] = "VANGUARDIA_concatenar-horizontal_";
    const char* foto = *nombreArchivo;
    strcat(nombre, foto);

    FILE *pf3 = fopen(nombre, "wb");
    if(!pf3)
    {
        puts("Error al crear archivo.");
        fclose(pf);
        fclose(pf2);
        return ERROR_CREAR_ARCHIVO;
    }

    encabezadoNuevo = encabezado;
    encabezadoNuevo.ancho += encabezado2.ancho;
    if(encabezado2.alto > encabezado.alto)
        encabezadoNuevo.alto = encabezado2.alto;
    encabezadoNuevo.tamImagen += encabezado2.tamImagen;
    encabezadoNuevo.tamArchivo += encabezado2.tamArchivo;

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf3);
    fwrite(&encabezadoNuevo, sizeof(t_header), 1, pf3);

    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
    fseek(pf2, encabezado2.comienzoImagen, SEEK_SET);
    fseek(pf3, encabezadoNuevo.comienzoImagen, SEEK_SET);

    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
    t_pixel** matImgOrig2 = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado2.alto, (size_t)encabezado2.ancho);

    char color [3]= {0,0,255};

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < encabezado.ancho; j++)

            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);

    for(int i = 0; i < encabezado2.alto; i++)
        for(int j = 0; j < encabezado2.ancho; j++)

            fread(&matImgOrig2[i][j], sizeof(t_pixel), 1, pf2);

    for (int i = 0; i < encabezadoNuevo.alto; i++)
    {
        if (i < encabezado.alto)
        {
            fwrite(matImgOrig[i], sizeof(t_pixel), encabezado.ancho, pf3);
        }
        else
        {
            for (int j = 0; j < encabezado.ancho; j++)
            {
                fwrite(&color, sizeof(t_pixel), 1, pf3);
            }
        }
        if (i < encabezado2.alto)
        {
            fwrite(matImgOrig2[i], sizeof(t_pixel), encabezado2.ancho, pf3);
        }
        else
        {
            for (int j = 0; j < encabezado2.ancho; j++)
            {
                fwrite(&color, sizeof(t_pixel), 1, pf3);
            }
        }
    }

    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);

    matrizDestruir((void**)matImgOrig2, (size_t)encabezado2.alto);

    fclose(pf);
    fclose(pf2);
    fclose(pf3);

    return TODO_OK;
}

void leerArgumentos(int argc, char* argv[], bool* argNegativo, bool* argEscalaDeGrises,
                   bool* argAumentarContraste, bool* argReducirContraste,
                   bool* argTonalidadAzul, bool* argTonalidadVerde, bool* argTonalidadRoja,
                   bool* argRotarDerecha, bool* argRotarIzquierda,
                   bool* argComodin, bool* argConcatenarHorizontal, bool* argConcatenarVertical,
                   bool* argEspejarVertical, bool* argEspejarHorizontal,
                   char** nombreArchivo, char** nombreArchivo2)
{

    bool banderas[14] = {false};
    char* banderasArgs[] = {
        "--negativo", "--escala-de-grises", "--aumentar-contraste", "--reducir-contraste",
        "--tonalidad-azul", "--tonalidad-verde", "--tonalidad-roja", "--rotar-derecha",
        "--rotar-izquierda", "--comodin", "--concatenar-horizontal", "--concatenar-vertical",
        "--espejar-horizontal", "--espejar-vertical"};

    bool primerArchivo = false;
    bool segundoArchivo = false;
    bool argAyuda = false;
    int contArgs = 0;

    for(int i=1; i<argc; i++)
    {

        if(strncmp(argv[i], "--", strlen("--")) != 0)
        {
            if(!primerArchivo)
            {
                *nombreArchivo = argv[i];
                primerArchivo = true;
                continue;
            }
            else if(!segundoArchivo)
            {
                *nombreArchivo2 = argv[i];
                segundoArchivo = true;
                continue;
            }
            else
            {
                printf("Se detectaron m�s de dos archivos, ten en cuenta que solo se utilizar�n los primeros dos. \n");
            }
        }

        bool banderaConocida = false;
        for (int j = 0; j <= 13; j++) {
            if (strcmp(argv[i], banderasArgs[j]) == 0) {
                banderas[j] = true;
                contArgs++;
                banderaConocida = true;
                break;
            }
        }

        if (banderaConocida) continue;

        if(strcmp(argv[i], "--ayuda") == 0)
        {
            puts("----Manipulador de Imagenes BMP---- \n"
                 "Este programa crea nuevas imagenes a partir de una foto BMP original. "
                 "Se debe enviar al menos 1 ruta de imagen BMP ejemplo 'hola.bmp' y alguna de las funciones detalladas a continuacion. "
                 "Se creara una nueva imagen por cada comando invocado. \n"
                 "Las posibles funciones para agregar son: \n"
                 "--negativo : Se invierten los colores de la imagen original. \n"
                 "--escala-de-grises : Unicamente con colores de la escala de grises. \n"
                 "--aumentar-contraste : Se aumenta el contraste un porcentaje de 0 a 100. \n"
                 "--reducir-contraste : Se reduce el contraste un porcentaje de 0 a 100. \n"
                 "--tonalidad-azul : Aumenta en un porcentaje de 0 a 100 la intensidad del color Azul \n"
                 "--tonalidad-verde : Aumenta en un porcentaje de 0 a 100 la intensidad del color Verde \n"
                 "--tonalidad-roja : Aumenta en un porcentaje de 0 a 100 la intensidad del color Rojo \n"
                 "--rotar-derecha : Gira la imagen 90 grados a la derecha \n"
                 "--rotar-izquierda : Gira la imagen 90 grados a la izquierda \n"
                 "--comodin : Sorpresa  \n"
                 "--concatenar-horizontal : *Requiere una segunda imagen como argumento*. Concatena ambas imagenes una al lado de la otra \n"
                 "--concatenar-vertical : *Requiere una segunda imagen como argumento*. Concatena ambas imagenes una arriba de la otra \n"
                 "--espejar-horizontal : Invierte horizontalmente la imagen \n"
                 "--espejar-horizontal : Invierte verticalmente la imagen\n"
                );
            contArgs++;
            argAyuda = true;
            continue;
        }
        printf("Comando %s no existe \n", argv[i]);
    }
    if(primerArchivo == 0 && !argAyuda)
    {
        puts("No se detect� ningun archivo bmp en los argumentos. Ejecute el comando --ayuda para m�s detalles");
    }
    if(contArgs == 0)
    {
        puts("No se detectaron llamadas a funciones dentro de los argumentos. Ejecute el comando --ayuda para visualizar las funcionalidades diponibles");
    }

    *argNegativo = banderas[0];
    *argEscalaDeGrises = banderas[1];
    *argAumentarContraste = banderas[2];
    *argReducirContraste = banderas[3];
    *argTonalidadAzul = banderas[4];
    *argTonalidadVerde = banderas[5];
    *argTonalidadRoja = banderas[6];
    *argRotarDerecha = banderas[7];
    *argRotarIzquierda = banderas[8];
    *argComodin = banderas[9];
    *argConcatenarHorizontal = banderas[10];
    *argConcatenarVertical = banderas[11];
    *argEspejarHorizontal = banderas[12];
    *argEspejarVertical = banderas[13];

}

int funcionBasica(void (*filtro)(t_pixel* pixel, unsigned char porcentaje), unsigned char porcentaje, char** nombreArchivo,
                                 char* nombreFiltro)
{
    FILE *pf = fopen(*nombreArchivo, "rb");
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

    char nombre[255] = "VANGUARDIA_";
    const char* filter = nombreFiltro;
    strcat(nombre, filter);
    const char* foto = *nombreArchivo;
    strcat(nombre, foto);

    FILE *pf2 = fopen(nombre, "wb");

    if(!pf2)
    {
        puts("Error al intentar abrir el archivo.");
        return ARCH_NO_ENCONTRADO;
    }

    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);

    fwrite(&encabezado,sizeof(t_header), 1, pf2);

    fseek(pf2, encabezado.comienzoImagen, SEEK_SET);

    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), encabezado.alto,encabezado.ancho);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < (encabezado.ancho); j++)
        {
            fread(&matImgOrig[i][j],sizeof(char),3,pf);
            filtro(&matImgOrig[i][j], porcentaje);
            fwrite(&matImgOrig[i][j],sizeof(char),3,pf2);
        }
    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);

    return TODO_OK;
}

