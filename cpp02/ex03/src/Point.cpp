/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/23 17:00:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	std::cout << "Default Point constructor called" << std::endl;
}
Point::Point(const float value1, const float value2): x(value1), y(value2) //member initializer list
{
	std::cout << "Point Float constructor called" << std::endl;
}
Point::~Point()
{
	std::cout << "Point Destructor called" << std::endl;
}
Point::Point(const Point& p): x(p.getX()), y(p.getY())
{
	std::cout << "Point Copy constructor called" << std::endl;
}
Point::Point(const Point a, const Point b): x(b.getX().toFloat() - a.getX().toFloat()), y(b.getY().toFloat() - a.getY().toFloat())
{
	std::cout << "Vector built x : " << x << " | y : " << y << std::endl;
}
Point&	Point::operator=(const Point& p)
{
	std::cout << "Point Copy assignment operator called" << std::endl;
	if (this == &p)
		return (*this);
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}

