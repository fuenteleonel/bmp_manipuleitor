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
    bool argNegativo = false, argEscalaDeGrises = false, argAumentarContraste = false, argReducirContraste = false,
    argTonalidadAzul = false, argTonalidadVerde = false, argTonalidadRoja = false, argRotarDerecha = false,
    argRotarIzquierda = false, argComodin = false, argConcatenarHorizontal = false, argConcatenarVertical = false,
    argEspejarVertical = false, argEspejarHorizontal = false;
    char* nombreArchivo;
    char* nombreArchivo2;

    leerArgumentos(argc, argv, &argNegativo, &argEscalaDeGrises,
                   &argAumentarContraste, &argReducirContraste,
                   &argTonalidadAzul, &argTonalidadVerde,&argTonalidadRoja,
                   &argRotarDerecha, &argRotarIzquierda,
                   &argComodin, &argConcatenarHorizontal, &argConcatenarVertical,
                   &argEspejarVertical, &argEspejarHorizontal,
                   &nombreArchivo, &nombreArchivo2);


//    if(argNegativo){
//        int codNegativo = negativo(pf, &encabezado);
//        if(codNegativo != TODO_OK){
//            printf("Error al generar archivo Negativo");
//        }
//    }
//
//    if(argEscalaDeGrises){
//        int codEscalaDeGrises = escalaDeGrises(pf, &encabezado);
//        if(codEscalaDeGrises != TODO_OK){
//            printf("Error al generar archivo Escala de Grises");
//        }
//    }
//
//    if(argAumentarContraste){
//        int codAumentarContraste = aumentarContraste(pf, &encabezado);
//        if(codAumentarContraste != TODO_OK){
//            printf("Error al generar archivo Aumentar Contraste");
//        }
//    }
//
//    if(argReducirContraste){
//        int codReducirContraste = reducirContraste(pf, &encabezado);
//        if(codReducirContraste != TODO_OK){
//            printf("Error al generar archivo Reducir Contraste");
//        }
//    }
//
//    if(argTonalidadAzul){
//        int codTonalidadAzul = tonalidad(pf, &encabezado, BLUE);
//        if(codTonalidadAzul != TODO_OK){
//            printf("Error al generar archivo Tonalidad Azul");
//        }
//    }
//
//    if(argTonalidadVerde){
//        int codTonalidadVerde = tonalidad(pf, &encabezado, GREEN);
//        if(codTonalidadVerde != TODO_OK){
//            printf("Error al generar archivo Tonalidad Verde");
//        }
//    }
//
//    if(argTonalidadRoja){
//        int codTonalidadRoja = tonalidad(pf, &encabezado, RED);
//        if(codTonalidadRoja != TODO_OK){
//            printf("Error al generar archivo Tonalidad Roja");
//        }
//    }


    if(argRotarDerecha){
        int codRotarDerecha = rotarDerecha();
        if(codRotarDerecha != TODO_OK){
            printf("Error al generar archivo Rotar Derecha");
        }
    }

    if(argRotarIzquierda){
        int codRotarIzquierda = rotarIzquierda();
        if(codRotarIzquierda != TODO_OK){
            printf("Error al generar archivo Rotar Izquierda");
        }
    }

//    if(argComodin){
//        int codComodin = comodin(pf, &encabezado);
//        if(codComodin != TODO_OK){
//            printf("Error al generar archivo Comodin");
//        }
//    }

    if(argConcatenarHorizontal){
        int codConcatenarHorizontal = concatenarHorizontal();
        if(codConcatenarHorizontal != TODO_OK){
            printf("Error al generar archivo Concatenar Horizontal");
        }
    }

    if(argConcatenarVertical){
        int codConcatenarVertical = concatenarVertical();
        if(codConcatenarVertical != TODO_OK){
            printf("Error al generar archivo Concatenar Vertical");
        }
    }

    if(argEspejarHorizontal){
        int codEspejarHorizontal = espejarHorizontal();
        if(codEspejarHorizontal != TODO_OK){
            printf("Error al generar archivo Espejar Horizontal");
        }
    }

    if(argEspejarVertical){
        int codEspejarVertical = espejarVertical();
        if(codEspejarVertical != TODO_OK){
            printf("Error al generar archivo Espejar Vertical");
        }
    }



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


    return TODO_OK;
}
