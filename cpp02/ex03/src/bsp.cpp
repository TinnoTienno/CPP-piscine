/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:22:36 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 18:54:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

int orient(Point const a, Point const b, Point const c) // remember that c is the point we are trying to find
{
	
	Point ab(a, b); // this are not mathematical points, they are vector which doesnt stop us in term of computer science
	Point ac(a, c);
	Fixed crossProduct = ab.getX().toFloat() * ac.getY().toFloat() - ac.getX().toFloat() * ab.getY().toFloat(); // to make a cross product i to draw a vector that is perpendicular to 2 other vectors
	if (roundf(crossProduct.toFloat()) >= 0) // if cross product is < 0 then ab is left of ac so to speak
		return (1);
	return (-1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) // To summarize, if the point is inside, then the point has to be on the same side of each segment of the triangle
{
	int turns;

	turns = orient(a, b, point) + orient(b, c, point) + orient(c, a, point);
	if (turns == 3 || turns == -3)
		return (1);
	return (0);
}
