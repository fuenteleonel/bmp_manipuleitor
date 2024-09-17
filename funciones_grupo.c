/*
    Integrantes del grupo. En caso de ser un grupo de dos integrantes, no completar el último campo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido: Fernandes
    Nombre: Matias
    DNI: 43909868
    Entrega: SI
    -----------------
    Apellido: Fuente
    Nombre: Leonel
    DNI: 42720496
    Entrega: SI
    -----------------
    Apellido: Wu
    Nombre: Pablo
    DNI: 41572967
    Entrega: SI
    -----------------
*/
#include "funciones_grupo.h"


int solucion(int argc, char* argv[])
{
///Todas las basicas

//    FILE *pf = fopen("unlam.bmp", "rb");
//    t_header encabezado;
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
//    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
//
//    FILE *pf2 = fopen("unlam-copia.bmp", "wb");
//
//    if(!pf2)
//    {
//        puts("Error al intentar abrir el archivo.");
//        return ARCH_NO_ENCONTRADO;
//    }
//
//    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf2);
//
//    fwrite(&encabezado,sizeof(t_header), 1, pf2);
//
//    fseek(pf2, encabezado.comienzoImagen, SEEK_SET);
//
//    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), encabezado.alto,encabezado.ancho);
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < (encabezado.ancho); j++)
//        {
//            fread(&matImgOrig[i][j],sizeof(char),3,pf);
//            negativo(&matImgOrig[i][j]);
//            fwrite(&matImgOrig[i][j],sizeof(char),3,pf2);
//        }
//    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
//    fclose(pf);
//    fclose(pf2);

///Achicar

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
//    FILE *pf2 = fopen("unlam-copia.bmp", "wb");
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
//    encabezadoNuevo.ancho /= ;
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

///Espejar

//    FILE *pf = fopen("unlam.bmp", "rb");
//    t_header encabezado;
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
//    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
//
//    FILE *pf2 = fopen("unlam-copia.bmp", "wb");
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
//
//    fwrite(&encabezado,sizeof(t_header), 1, pf2);
//
//    fseek(pf2, encabezado.comienzoImagen, SEEK_SET);

///Espejar Vertical

//    t_pixel** matEspejadaV = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
//
//    for(int i = encabezado.alto - 1; i >= 0; i--)
//          for(int j = 0; j < encabezado.ancho; j++)
//            fread(&matEspejadaV[i][j], sizeof(t_pixel), 1, pf);
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < encabezado.ancho; j++)
//            fwrite(&matEspejadaV[i][j], sizeof(t_pixel), 1, pf2);
//
//    matrizDestruir((void**)matEspejadaV, (size_t)encabezado.alto);
//    fclose(pf);
//    fclose(pf2);

///Espejar Horizontal

//    t_pixel** matEspejadaH = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = encabezado.ancho - 1; j >= 0; j--)
//            fread(&matEspejadaH[i][j], sizeof(t_pixel), 1, pf);
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < encabezado.ancho; j++)
//            fwrite(&matEspejadaH[i][j], sizeof(t_pixel), 1, pf2);
//
//    matrizDestruir((void**)matEspejadaH, (size_t)encabezado.alto);
//    fclose(pf);
//    fclose(pf2);
//

///ConcatenarVertical

    FILE *pf = fopen("unlam2.bmp", "rb");
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

    FILE *pf2 = fopen("unlam.bmp", "rb");

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

    FILE *pf3 = fopen("unlam-concatenada.bmp", "wb");
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
        for(int j = 0; j < encabezado2.ancho; j++)
            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf2);

    for(int i = 0; i < encabezado2.alto; i++)
    {
        for(int j = 0; j < encabezado2.ancho; j++)
        {
            fwrite(&matImgOrig[i][j], sizeof(t_pixel), 1, pf3);
        }
        if(encabezado2.ancho < encabezado.ancho)
        {
            for(int i=0; i<(encabezado.ancho - encabezado2.ancho); i++)
                fwrite(&color, sizeof(char), 3, pf3);
        }
    }

    matrizDestruir((void**)matImgOrig, (size_t)encabezado2.alto);

    matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);

    for(int i = 0; i < encabezado.alto; i++)
        for(int j = 0; j < encabezado.ancho; j++)
            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);

    for(int i = 0; i < encabezado.alto; i++)
    {
        for(int j = 0; j < encabezado.ancho; j++)
        {
            fwrite(&matImgOrig[i][j], sizeof(t_pixel), 1, pf3);
        }
        if(encabezado.ancho < encabezado2.ancho)
        {
            for(int i=0; i<(encabezado2.ancho - encabezado.ancho); i++)
                fwrite(&color, sizeof(char), 3, pf3);
        }
    }
    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
    fclose(pf);
    fclose(pf2);
    fclose(pf3);

///ConcatenarHorizontal

//    FILE *pf = fopen("unlam2.bmp", "rb");
//    t_header encabezado, encabezado2, encabezadoNuevo;
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
//
//    FILE *pf2 = fopen("unlam.bmp", "rb");
//
//    if(!pf2)
//    {
//        puts("Error al intentar abrir el archivo.");
//        fclose(pf);
//        return ARCH_NO_ENCONTRADO;
//    }
//
//    fread(&tipoFichero, sizeof(unsigned short), 1, pf2);
//
//    if(tipoFichero != TIPO_BMP)
//    {
//        fclose(pf);
//        fclose(pf2);
//        return FORMATO_INCORRECTO;
//    }
//
//    fread(&encabezado2,sizeof(t_header), 1, pf2);
//
//    FILE *pf3 = fopen("unlam-concatenada.bmp", "wb");
//    if(!pf3)
//    {
//        puts("Error al crear archivo.");
//        fclose(pf);
//        fclose(pf2);
//        return ERROR_CREAR_ARCHIVO;
//    }
//
//    encabezadoNuevo = encabezado;
//    encabezadoNuevo.ancho += encabezado2.ancho;
//    if(encabezado2.alto > encabezado.alto)
//        encabezadoNuevo.alto = encabezado2.alto;
//    encabezadoNuevo.tamImagen += encabezado2.tamImagen;
//    encabezadoNuevo.tamArchivo += encabezado2.tamArchivo;
//
//    fwrite(&tipoFichero, sizeof(unsigned short), 1, pf3);
//    fwrite(&encabezadoNuevo, sizeof(t_header), 1, pf3);
//
//    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
//    fseek(pf2, encabezado2.comienzoImagen, SEEK_SET);
//    fseek(pf3, encabezadoNuevo.comienzoImagen, SEEK_SET);
//
//    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
//    t_pixel** matImgOrig2 = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado2.alto, (size_t)encabezado2.ancho);
//
//    char color [3]= {0,0,255};
//
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < encabezado.ancho; j++)
//
//            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);
//
//    for(int i = 0; i < encabezado2.alto; i++)
//        for(int j = 0; j < encabezado2.ancho; j++)
//
//            fread(&matImgOrig2[i][j], sizeof(t_pixel), 1, pf2);
//
//    for (int i = 0; i < encabezadoNuevo.alto; i++)
//    {
//        if (i < encabezado.alto)
//        {
//            fwrite(matImgOrig[i], sizeof(t_pixel), encabezado.ancho, pf3);
//        }
//        else
//        {
//            for (int j = 0; j < encabezado.ancho; j++)
//            {
//                fwrite(&color, sizeof(t_pixel), 1, pf3);
//            }
//        }
//        if (i < encabezado2.alto)
//        {
//            fwrite(matImgOrig2[i], sizeof(t_pixel), encabezado2.ancho, pf3);
//        }
//        else
//        {
//            for (int j = 0; j < encabezado2.ancho; j++)
//            {
//                fwrite(&color, sizeof(t_pixel), 1, pf3);
//            }
//        }
//    }
//
//    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
//
//    matrizDestruir((void**)matImgOrig2, (size_t)encabezado2.alto);
//
//    fclose(pf);
//    fclose(pf2);
//    fclose(pf3);


///Rotar
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
//
//    FILE *pf2 = fopen("unlam-copia.bmp", "wb");
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
//    encabezadoNuevo.alto = encabezado.ancho;
//    encabezadoNuevo.ancho = encabezado.alto;
//
//    fwrite(&encabezadoNuevo,sizeof(t_header), 1, pf2);
//
//    fseek(pf, encabezado.comienzoImagen, SEEK_SET);
//    fseek(pf2, encabezadoNuevo.comienzoImagen, SEEK_SET);
//
//    t_pixel** matImgOrig = (t_pixel**)matrizCrear(sizeof(t_pixel), (size_t)encabezado.alto, (size_t)encabezado.ancho);
//
/////RotarDerecha
////    for(int i = 0; i < encabezado.alto; i++)
////        for(int j = 0; j < encabezado.ancho; j++)
////            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);
////
////    for(int i = encabezado.ancho - 1; i >= 0; i--)
////        for(int j = 0; j < encabezado.alto; j++)
////            fwrite(&matImgOrig[j][i], sizeof(t_pixel), 1, pf2);
//
/////RotarIzq
//    for(int i = 0; i < encabezado.alto; i++)
//        for(int j = 0; j < encabezado.ancho; j++)
//            fread(&matImgOrig[i][j], sizeof(t_pixel), 1, pf);
//
//    for(int i = 0; i < encabezado.ancho; i++)
//        for(int j = encabezado.alto - 1; j >= 0; j--)
//            fwrite(&matImgOrig[j][i], sizeof(t_pixel), 1, pf2);
//
//    matrizDestruir((void**)matImgOrig, (size_t)encabezado.alto);
//    fclose(pf);
//    fclose(pf2);


    return 0;
}
