/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:36 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/25 17:40:57 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void output_help()
{
	ft_putendl("Hotkeys:\n");
	ft_putendl("## W A S D - move camera Up/Left/Down/Right");
	ft_putendl("## Arrows Up/Down/Left/Right - turn camera Up/Down/Left/Right");
	ft_putendl("## R - redraw scene");
	ft_putendl("## Esc - exit");
	ft_putendl("--------------------------------");

	ft_putendl("Syntax requirements for scene:\n");
	ft_putendl("## NO TABULATION between words(separated by spaces)"
		   " ONLY SPACES");
	ft_putendl("## Add tags for \"scene\" and \"objects\"");
	ft_putendl("## Add CURLY brackets for all text objects");
	ft_putendl("## CURLY brackets \"scene\" and \"camera\": \"{\" & \"};\"");
	ft_putendl("## CURLY brackets other: \"{\" & \"}\"");
	ft_putendl("## Add USUAL brackets for all configurations + spaces");
	ft_putendl("## New line \"\\n\" after curly brackets, tags and config");
	ft_putendl("## For example, use prepared scenes");
	ft_putendl("--------------------------------");

	ft_putendl("Text objects description:\n");
	ft_putendl("# Scene:");
	ft_putendl("## Camera: !(only one)");
	ft_putendl("## (vec_int_3)pos - camera position");
	ft_putendl("## (vec_int_3)dir - camera direction");
	ft_putendl("## Light:");
	ft_putendl("## (string)type - type of light (Directional, Point, Ambient");
	ft_putendl("## (vec_int_3)pos - light position");
	ft_putendl("## (float)intensity - light intensity");
	ft_putendl("## (!only for Directional)(vec_int_3)dir - light direction");
	ft_putendl("## (!only for Directional)(vec_int_3)dir - light direction");


}