/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:48:31 by anhloba           #+#    #+#             */
/*   Updated: 2018/08/22 14:22:02 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek	rot_x(t_r *rtv, t_vek d)
{
	t_vek	vek;

	vek.x = d.x * cos(rtv->a) + d.z * sin(rtv->a);
	vek.y = d.y;
	vek.z = d.z * cos(rtv->a) - d.x * sin(rtv->a);
	return (vek);
}

t_vek	rot_y(t_r *rtv, t_vek d)
{
	t_vek	vek;

	vek.x = d.x;
	vek.y = d.y * cos(rtv->b) + d.z * sin(rtv->b);
	vek.z = d.z * cos(rtv->b) - d.y * sin(rtv->b);
	return (rot_x(rtv, vek));
}

t_vek	rot_z(t_r *rtv, t_vek d)
{
	t_vek	vek;

	vek.x = d.x * cos(rtv->c) - d.y * sin(rtv->c);
	vek.y = d.x * sin(rtv->c) + d.y * cos(rtv->c);
	vek.z = d.z;
	return (rot_y(rtv, vek));
}
