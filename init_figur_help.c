/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figur_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:16:14 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/26 12:16:15 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	helper(char *list, t_r *rtv)
{
	if (ft_strstr(list, "<Scene_name>Space</Scene_name>") != 0)
		rtv->img_background = 1;
	if (ft_strstr(list, "<Scene_name>ligth_box</Scene_name>") != 0)
		rtv->img_background = 2;
	if (ft_strstr(list, "<Scene_name>ligth_space2</Scene_name>") != 0)
		rtv->img_background = 3;
}
