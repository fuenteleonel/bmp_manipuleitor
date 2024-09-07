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
