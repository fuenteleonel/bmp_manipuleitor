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

    char* neg = "negativo_";
    char* escalaGrises = "escala-de-grises_";
    char* aumentarCont = "aumentar-contraste_";
    char* reducirCont = "reducir-contraste_";
    char* tonRoja = "tonalidad-roja_";
    char* tonAzul = "tonalidad-azul_";
    char* tonVerde = "tonalidad-verde_";

    leerArgumentos(argc, argv, &argNegativo, &argEscalaDeGrises,
                   &argAumentarContraste, &argReducirContraste,
                   &argTonalidadAzul, &argTonalidadVerde,&argTonalidadRoja,
                   &argRotarDerecha, &argRotarIzquierda,
                   &argComodin, &argConcatenarHorizontal, &argConcatenarVertical,
                   &argEspejarVertical, &argEspejarHorizontal,
                   &nombreArchivo, &nombreArchivo2);


    void (*filtro)(t_pixel* pixel, unsigned char porcentaje);


    if(argNegativo)
    {
        filtro = negativo;
        int codNegativo = funcionBasica(filtro, 0, &nombreArchivo, neg);
        if(codNegativo != TODO_OK)
        {
            printf("Error al generar archivo Negativo");
        }
    }

    if(argEscalaDeGrises)
    {
        filtro = escalaDeGrises;
        int codEscalaDeGrises = funcionBasica(filtro, 0, &nombreArchivo, escalaGrises);
        if(codEscalaDeGrises != TODO_OK)
        {
            printf("Error al generar archivo Escala de Grises");
        }
    }

    if(argAumentarContraste)
    {
        filtro = aumentarContraste;
        int codAumentarContraste = funcionBasica(filtro, 25, &nombreArchivo, aumentarCont);
        if(codAumentarContraste != TODO_OK)
        {
            printf("Error al generar archivo Aumentar Contraste");
        }
    }

    if(argReducirContraste)
    {
        filtro = reducirContraste;
        int codReducirContraste = funcionBasica(filtro, 25, &nombreArchivo, reducirCont);
        if(codReducirContraste != TODO_OK)
        {
            printf("Error al generar archivo Reducir Contraste");
        }
    }

    if(argTonalidadAzul)
    {
        filtro = tonalidadAzul;
        int codTonalidadAzul = funcionBasica(filtro, 25, &nombreArchivo, tonAzul);
        if(codTonalidadAzul != TODO_OK)
        {
            printf("Error al generar archivo Tonalidad Azul");
        }
    }

    if(argTonalidadVerde)
    {
        filtro = tonalidadVerde;
        int codTonalidadVerde = funcionBasica(filtro, 25, &nombreArchivo, tonVerde);
        if(codTonalidadVerde != TODO_OK)
        {
            printf("Error al generar archivo Tonalidad Verde");
        }
    }

    if(argTonalidadRoja)
    {
        filtro = tonalidadRoja;
        int codTonalidadRoja = funcionBasica(filtro, 25, &nombreArchivo, tonRoja);
        if(codTonalidadRoja != TODO_OK)
        {
            printf("Error al generar archivo Tonalidad Roja");
        }
    }


    if(argRotarDerecha)
    {
        int codRotarDerecha = rotarDerecha(&nombreArchivo);
        if(codRotarDerecha != TODO_OK)
        {
            printf("Error al generar archivo Rotar Derecha");
        }
    }

    if(argRotarIzquierda)
    {
        int codRotarIzquierda = rotarIzquierda(&nombreArchivo);
        if(codRotarIzquierda != TODO_OK)
        {
            printf("Error al generar archivo Rotar Izquierda");
        }
    }

//    if(argComodin){
//        int codComodin = comodin(pf, &encabezado);
//        if(codComodin != TODO_OK){
//            printf("Error al generar archivo Comodin");
//        }
//    }

    if(argConcatenarHorizontal)
    {
        int codConcatenarHorizontal = concatenarHorizontal(&nombreArchivo, &nombreArchivo2);
        if(codConcatenarHorizontal != TODO_OK)
        {
            printf("Error al generar archivo Concatenar Horizontal");
        }
    }

    if(argConcatenarVertical)
    {
        int codConcatenarVertical = concatenarVertical(&nombreArchivo,&nombreArchivo2);
        if(codConcatenarVertical != TODO_OK)
        {
            printf("Error al generar archivo Concatenar Vertical");
        }
    }

    if(argEspejarHorizontal)
    {
        int codEspejarHorizontal = espejarHorizontal(&nombreArchivo);
        if(codEspejarHorizontal != TODO_OK)
        {
            printf("Error al generar archivo Espejar Horizontal");
        }
    }

    if(argEspejarVertical)
    {
        int codEspejarVertical = espejarVertical(&nombreArchivo);
        if(codEspejarVertical != TODO_OK)
        {
            printf("Error al generar archivo Espejar Vertical");
        }
    }


    return TODO_OK;
}
