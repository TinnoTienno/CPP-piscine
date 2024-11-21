/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:12 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 14:40:26 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "RPN.hpp"
#include <exception>

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error("format : ./RPN number number operator"));
		RPN rpn(argv[1]);
		std::cout << rpn.getRes() << std::endl;
	}
	catch (RPN::WrongInputException& e)
	{
		std::cout << e.what() << e.getArg() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}