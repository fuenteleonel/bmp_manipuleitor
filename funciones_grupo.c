/*
    Integrantes del grupo. En caso de ser un grupo de dos integrantes, no completar el último campo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido: Fernandes, Matias
    DNI: 43909868
    Entrega: SI
    -----------------
    Apellido: Fuente, Leonel
    DNI: 42720496
    Entrega: SI
    -----------------
    Apellido: Wu, Pablo
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
    char* com = "comodin_";
    char* escalaGrises = "escala-de-grises_";
    char* aumentarCont = "aumentar-contraste_";
    char* reducirCont = "reducir-contraste_";
    char* tonRoja = "tonalidad-roja_";
    char* tonAzul = "tonalidad-azul_";
    char* tonVerde = "tonalidad-verde_";

    unsigned char porcAumCont, porcRedCont, porcTonAzul, porcTonVerde, porcTonRoja;

    leerArgumentos(argc, argv, &argNegativo, &argEscalaDeGrises,
                   &argAumentarContraste, &argReducirContraste,
                   &argTonalidadAzul, &argTonalidadVerde,&argTonalidadRoja,
                   &argRotarDerecha, &argRotarIzquierda,
                   &argComodin, &argConcatenarHorizontal, &argConcatenarVertical,
                   &argEspejarVertical, &argEspejarHorizontal,
                   &nombreArchivo, &nombreArchivo2,
                   &porcAumCont, &porcRedCont, &porcTonAzul, &porcTonVerde, &porcTonRoja);

    void (*filtro)(t_pixel* pixel, unsigned char porcentaje);

    int codigoFuncion;

    if(argNegativo)
    {
        filtro = negativo;
        codigoFuncion = funcionBasica(filtro, 0, &nombreArchivo, neg);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Negativo.");
    }
    if(argComodin)
    {
        filtro = comodin;
        codigoFuncion = funcionBasica(filtro, 0, &nombreArchivo, com);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Comodin.");
    }
    if(argEscalaDeGrises)
    {
        filtro = escalaDeGrises;
        codigoFuncion = funcionBasica(filtro, 0, &nombreArchivo, escalaGrises);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Escala de Grises.");
    }
    if(argAumentarContraste)
    {
        filtro = aumentarContraste;
        codigoFuncion = funcionBasica(filtro, porcAumCont, &nombreArchivo, aumentarCont);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Aumentar Contraste.");
    }
    if(argReducirContraste)
    {
        filtro = reducirContraste;
        codigoFuncion = funcionBasica(filtro, porcRedCont, &nombreArchivo, reducirCont);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Reducir Contraste.");
    }
    if(argTonalidadAzul)
    {
        filtro = tonalidadAzul;
        codigoFuncion = funcionBasica(filtro, porcTonAzul, &nombreArchivo, tonAzul);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Tonalidad Azul.");
    }
    if(argTonalidadVerde)
    {
        filtro = tonalidadVerde;
        codigoFuncion = funcionBasica(filtro, porcTonVerde, &nombreArchivo, tonVerde);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Tonalidad Verde.");
    }
    if(argTonalidadRoja)
    {
        filtro = tonalidadRoja;
        codigoFuncion = funcionBasica(filtro, porcTonRoja, &nombreArchivo, tonRoja);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Tonalidad Roja.");
    }
    if(argRotarDerecha)
    {
        codigoFuncion = rotarDerecha(&nombreArchivo);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Rotar Derecha.");
    }
    if(argRotarIzquierda)
    {
        codigoFuncion = rotarIzquierda(&nombreArchivo);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Rotar Izquierda.");
    }
    if(argConcatenarHorizontal)
    {
        codigoFuncion = concatenarHorizontal(&nombreArchivo, &nombreArchivo2);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Concatenar Horizontal.");
    }
    if(argConcatenarVertical)
    {
        codigoFuncion = concatenarVertical(&nombreArchivo,&nombreArchivo2);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Concatenar Vertical.");
    }
    if(argEspejarHorizontal)
    {
        codigoFuncion = espejarHorizontal(&nombreArchivo);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Espejar Horizontal.");
    }
    if(argEspejarVertical)
    {
        codigoFuncion = espejarVertical(&nombreArchivo);
        if(codigoFuncion != TODO_OK)
            printf("Error al generar archivo Espejar Vertical.");
    }
    return TODO_OK;
}
