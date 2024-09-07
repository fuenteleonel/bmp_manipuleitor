#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct
{
    unsigned char color[3];
    //unsigned int profundidad; //Esta estructura admite formatos de distinta profundidad de color.

}t_pixel;

typedef struct
{
    unsigned int tamArchivo;
    unsigned int tamEncabezado;
    unsigned int ancho;
    unsigned int alto;
    unsigned short profundidad;
}t_metadata;

typedef struct
{
    unsigned int tamArchivo;
    unsigned int reservado;
    unsigned int comienzoImagen;   // Por eso dejo espacio para ambas cosas
    unsigned int tamEncabezado;    // El tamaño del encabezado no siempre coincide con el comienzo de la imagen
    unsigned int ancho;
    unsigned int alto;
    unsigned short numPlanos;
    unsigned short profundidad;
    unsigned int compresion;
    unsigned int tamImagen;
    unsigned int resolH;
    unsigned int resolV;
    unsigned int tamColor;
    unsigned int cantColores;
}t_header;

#endif // ESTRUCTURAS_H_INCLUDED
