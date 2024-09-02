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
#include "estructuras.h"

#define TIPO_BMP 0x4D42
#define RED 2
#define GREEN 1
#define BLUE 0
#define TAM_HEADER 54
#define ARCH_NO_ENCONTRADO 3
#define FORMATO_INCORRECTO 4

void matrizDestruir(void** mat,int filas)
{
    void** ult = mat + filas - 1;
    for(void** i= mat; i<= ult;i++)
        free(*i);
    free(mat);
}

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

    matrizCrear(encabezado.tamArchivo, encabezado.alto,encabezado.ancho);

    return 0;
}
