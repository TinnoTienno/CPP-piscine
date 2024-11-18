/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:29:34 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	// std::cout << "Default point constructor called" << std::endl;
}

Point::Point(const float value1, const float value2): m_x(value1), m_y(value2) //member initializer list
{
	// std::cout << "Point float constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Point::Point(const Point& obj): m_x(obj.getX()), m_y(obj.getY())
{
	// std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(const Point a, const Point b): m_x(b.getX().toFloat() - a.getX().toFloat()), m_y(b.getY().toFloat() - a.getY().toFloat())
{
	// std::cout << "Point vector constructor called" << std::endl;
}

Point&	Point::operator=(const Point&) //useless af
{
	// std::cout << "Point copy assignment operator called" << std::endl;
	return (*this);
}

Fixed	Point::getX() const { return (m_x); }

Fixed	Point::getY() const { return (m_y); }

