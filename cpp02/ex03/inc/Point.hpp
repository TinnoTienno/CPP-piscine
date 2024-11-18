/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:19:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private :
		const Fixed m_x;
		const Fixed m_y;
	public :
		Point();
		Point(const Point&);
		Point(const float, const float);
		Point(const Point, const Point);
		Point&	operator=(const Point&);
		~Point();
		
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif