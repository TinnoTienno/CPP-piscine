/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:39:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 16:46:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp" 
#include <iostream>
#include <stdlib.h>

int multiply(int i)
{
	return (i * i);
}
int main(int argc, char **argv)
{
	if (argc != 4 | atoi(argv[1]) < 0)
	{
		std::cout << "format : ./span range ShortestSpan longestSpan" << std::endl;
		return 1;
	}
	try
	{
		int size = atoi(argv[1]);
		Span arr(size);
		
		arr.addRange(size, multiply);
		std::cout << "Min : " << arr.shortestSpan(atoi(argv[2])) << std::endl;
		std::cout << "Max : " << arr.longestSpan(atoi(argv[3])) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}