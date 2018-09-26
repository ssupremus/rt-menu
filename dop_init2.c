/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:40:56 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 21:44:41 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	dop_init_mebius(double *r, double *rr)
{
	if (*r < 0)
		*r = 0.0;
	if (*rr < -1.5)
		*rr = -1.5;
}

void	dop_init_torus(double *r, double *rr)
{
	if (*rr < 0.1)
		*rr = 0.1;
	if (*r < 0)
		*r = 0.0;
}
