#include "funciones_fernandes.h"

void reducirContraste(t_pixel *pixel, unsigned char porcentaje)
{
    unsigned char promedio = (pixel->color[BLUE] + pixel->color[RED] + pixel->color[GREEN])/3;

    if(promedio < VALOR_MEDIO_COLOR)
    {
        aplicarPorcentaje(&pixel->color[BLUE], porcentaje, VALOR_MEDIO_COLOR);
        aplicarPorcentaje(&pixel->color[RED], porcentaje, VALOR_MEDIO_COLOR);
        aplicarPorcentaje(&pixel->color[GREEN], porcentaje, VALOR_MEDIO_COLOR);

    }
    else
    {
        aplicarPorcentajeMin(&pixel->color[BLUE], porcentaje, VALOR_MEDIO_COLOR);
        aplicarPorcentajeMin(&pixel->color[RED], porcentaje, VALOR_MEDIO_COLOR);
        aplicarPorcentajeMin(&pixel->color[GREEN], porcentaje, VALOR_MEDIO_COLOR);

    }
}
