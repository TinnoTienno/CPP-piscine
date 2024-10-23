/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:22:36 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/23 16:58:01 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

int orient(Point const a, Point const b, Point const c)
{
	
	Point ab(a, b);
	Point ac(a, c);
	float crossProduct = ab.getX().toFloat() * ac.getY().toFloat() - ac.getX().toFloat() * ab.getY().toFloat();
	if (roundf(crossProduct) >= 0)
		return (1);
	return (-1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int turns;

	turns = orient(a, b, point) + orient(b, c, point) + orient(c, a, point);
	if (turns == 3 || turns == -3)
		return (1);
	return (0);
}
