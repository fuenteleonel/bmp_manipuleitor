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

    FILE *pf2 = fopen("unlam-copia.bmp", "wb");

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
    {
        for(int j = 0; j < (encabezado.ancho); j++)
        {

            fread(&matImgOrig[i][j],sizeof(char),3,pf);

            reducirContraste(&matImgOrig[i][j], 25);

            fwrite(&matImgOrig[i][j],sizeof(char),3,pf2);

        }
    }



    return 0;
}
