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
