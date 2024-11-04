/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 18:55:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	// std::cout << "Default point constructor called" << std::endl;
}

Point::Point(const float value1, const float value2): x(value1), y(value2) //member initializer list
{
	// std::cout << "Point float constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Point::Point(const Point& obj): x(obj.getX()), y(obj.getY())
{
	// std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(const Point a, const Point b): x(b.getX().toFloat() - a.getX().toFloat()), y(b.getY().toFloat() - a.getY().toFloat())
{
	// std::cout << "Point vector constructor called" << std::endl;
}

Point&	Point::operator=(const Point&) //useless af
{
	// std::cout << "Point copy assignment operator called" << std::endl;
	return (*this);
}

Fixed	Point::getX() const { return (x); }

Fixed	Point::getY() const { return (y); }

