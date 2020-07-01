/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:36 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/01 15:04:31 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	output_help(void)
{
	ft_putendl("Hotkeys:\n");
	ft_putendl("## W A S D - move camera Up/Left/Down/Right");
	ft_putendl("## Arrows Up/Down/Left/Right - turn camera Up/Down/Left/Right");
	ft_putendl("## Top row +/- - Zoom in/Zoom out");
	ft_putendl("## R - redraw scene");
	ft_putendl("## Esc - exit");
	ft_putendl("--------------------------------");
	ft_putendl("Syntax requirements for scene:\n");
	ft_putendl("## NO TABULATION between words(separated by spaces)"
			" ONLY SPACES");
	ft_putendl("## Add tags \"scene\" (camera & lights) and \"objects\" "
			"(figures)");
	ft_putendl("## Tag \"scene\" is the first, \"objects\" is second");
	ft_putendl("## Add CURLY brackets for all text objects");
	ft_putendl("## CURLY brackets \"scene\" and \"objects\": \"{\" & \"};\"");
	ft_putendl("## CURLY brackets other: \"{\" & \"}\"");
	ft_putendl("## Add USUAL brackets + spaces for all object's "
			"configurations");
	ft_putendl("## New line \"\\n\" after curly brackets, tags and config");
	ft_putendl("## For example, use prepared scenes");
	ft_putendl("## Full information in README");
}
