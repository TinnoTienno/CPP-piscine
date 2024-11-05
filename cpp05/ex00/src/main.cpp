/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 12:49:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Bureaucrat John("John", -1); // Test a grade thats too low at definition
	}
	catch (std::exception &e)Now that you have bureaucrats, let’s give them something to do. What better activity
	{
		std::cerr << "Test1 : " << std::endl << e.what();
	}
}