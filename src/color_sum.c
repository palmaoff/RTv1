//
// Created by User on 20.05.2020.
//

#include "RTv1.h"

t_color   color_sum(t_color a, t_color b)
{
    t_color color;

    color.r = a.r + b.r;
    color.g = a.g + b.g;
    color.b = a.b + b.b;
    return (color);
}