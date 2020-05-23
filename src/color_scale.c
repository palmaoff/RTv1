//
// Created by User on 21.05.2020.
//

#include "RTv1.h"

t_color   color_scale(t_color a, double b)
{
    t_color color;

    color.r = a.r * b;
    color.g = a.g * b;
    color.b = a.b * b;
    return (color);
}
