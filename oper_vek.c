/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_vek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:09:31 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:30:59 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek	vek_sum(t_vek v1, t_vek v2)
{
	t_vek	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	sum.z = v1.z + v2.z;
	return (sum);
}

t_vek	vek_sub(t_vek v1, t_vek v2)
{
	t_vek	sub;

	sub.x = v1.x - v2.x;
	sub.y = v1.y - v2.y;
	sub.z = v1.z - v2.z;
	return (sub);
}

t_vek	vek_num(t_vek v1, double n)
{
	t_vek	mult;

	mult.x = v1.x * n;
	mult.y = v1.y * n;
	mult.z = v1.z * n;
	return (mult);
}

t_vek	vek_mult(t_vek v1, t_vek v2)
{
	t_vek	mult;

	mult.x = v1.x * v2.x;
	mult.y = v1.y * v2.y;
	mult.z = v1.z * v2.z;
	return (mult);
}

t_vek	vek_new(double x, double y, double z)
{
	t_vek	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
