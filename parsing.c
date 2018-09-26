/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:44:26 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 15:40:05 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	zero_count(t_r *rtv)
{
	rtv->count_fgr = 0;
	rtv->count_light = 0;
	rtv->count_cam = 0;
}

void	check_scene(t_r *rtv)
{
	if (rtv->count_cam != 1)
		error1("Need fix a camera!", rtv);
	if (rtv->count_light < 1)
		error1("Need to add light!", rtv);
	if (rtv->count_fgr < 1)
		error1("Need to add a figure!", rtv);
}

void	fig_musiv_help(int i, t_r *rtv)
{
	if (ft_strstr(rtv->list[i], "<Mebius>") != 0)
	{
		if (pars_fig_close(rtv, i, "<Mebius>", "</Mebius>") == 1)
			rtv->count_fgr++;
	}
	else if (ft_strstr(rtv->list[i], "<Torus>") != 0)
	{
		if (pars_fig_close(rtv, i, "<Torus>", "</Torus>") == 1)
			rtv->count_fgr++;
	}
	else if (ft_strstr(rtv->list[i], "<Parabol>") != 0)
	{
		if (pars_fig_close(rtv, i, "<Parabol>", "</Parabol>") == 1)
			rtv->count_fgr++;
	}
	else if (ft_strstr(rtv->list[i], "<Light>") != 0)
	{
		if (pars_fig_close(rtv, i, "<Light>", "</Light>") == 1)
			rtv->count_light++;
	}
	else if (ft_strstr(rtv->list[i], "<Cam>") != 0)
	{
		if (pars_fig_close(rtv, i, "<Cam>", "</Cam>") == 1)
			rtv->count_cam++;
	}
}

void	fig_musiv(t_r *rtv)
{
	int i;

	i = -1;
	while (rtv->list[++i] != NULL)
	{
		if (ft_strstr(rtv->list[i], "<Sphere>") != 0 &&
		pars_fig_close(rtv, i, "<Sphere>", "</Sphere>") == 1)
			rtv->count_fgr++;
		else if (ft_strstr(rtv->list[i], "<Cylinder>") != 0 &&
		pars_fig_close(rtv, i, "<Cylinder>", "</Cylinder>") == 1)
			rtv->count_fgr++;
		else if (ft_strstr(rtv->list[i], "<Cone>") != 0 &&
		pars_fig_close(rtv, i, "<Cone>", "</Cone>") == 1)
			rtv->count_fgr++;
		else if (ft_strstr(rtv->list[i], "<Plane>") != 0 &&
		pars_fig_close(rtv, i, "<Plane>", "</Plane>") == 1)
			rtv->count_fgr++;
		else if (ft_strstr(rtv->list[i], "<Mebius>") != 0 ||
		ft_strstr(rtv->list[i], "<Torus>") != 0 ||
		ft_strstr(rtv->list[i], "<Light>") != 0 ||
		ft_strstr(rtv->list[i], "<Cam>") != 0 ||
		ft_strstr(rtv->list[i], "<Parabol>") != 0)
			fig_musiv_help(i, rtv);
	}
	check_scene(rtv);
}

void	parsing(char *av, t_r *rtv)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*buff;
	char	**res;

	buff = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(0);
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = join_free(tmp, buff);
	}
	error2(ret, fd, av, rtv);
	res = split2(tmp, '\n');
	rtv->list = res;
	close(fd);
	ft_strdel(&tmp);
	ft_strdel(&buff);
	zero_count(rtv);
	fig_musiv(rtv);
}
