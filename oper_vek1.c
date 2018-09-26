/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_vek1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:32:54 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:42:21 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek	vek_norm(t_vek v)
{
	double len;

	len = vek_len(v);
	v.x = v.x / len;
	v.y = v.y / len;
	v.z = v.z / len;
	return (v);
}

t_vek	conversion(t_r *rtv, int x, int y, int z)
{
	t_vek res;

	res.x = (double)x * rtv->rama.w / rtv->w;
	res.y = (double)y * rtv->rama.h / rtv->h;
	res.z = (double)z;
	return (res);
}

t_vek	vek_cross(t_vek va, t_vek vb)
{
	t_vek v;

	v.x = va.y * vb.z - va.z * vb.y;
	v.y = va.z * vb.x - va.x * vb.z;
	v.z = va.x * vb.y - va.y * vb.x;
	return (v);
}

t_vek	reflect(t_vek r, t_vek n)
{
	return (vek_norm(vek_sub(vek_num(n, vek_skal(r, n) * 2), r)));
}

double	mix(double a, double b, double mix)
{
	return (b * mix + a * (1 - mix));
}
