/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:15:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/23 16:57:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	
	Point a(10.0,0.0);
	Point b(0.0,0.0);
	Point c(0.0,10.0);

	Point point(10.0, 0.0);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle ABC" << std::endl;
	else
		std::cout << "Point is outside the triangle ABC" << std::endl;
	return 0;
}