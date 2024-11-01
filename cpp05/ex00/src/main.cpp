/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/01 13:13:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Bureaucrat John("John", 151); // Test a grade thats too low at definition
	}
	catch (std::exception &e)
	{
		std::cerr << "Test1 : " << e.what();
	}
	try
	{
		Bureaucrat	Jim("Jim", 150);
		Jim.decrement();
	}
	catch (std::exception &e)
	{
		std::cerr << "Test2 : " << e.what();	
	}
	try
	{
		Bureaucrat	George("George", 1);
		George.increment();
	}
	catch (std::exception &e)
	{
		std::cerr << "Test3 : " << std::endl << e.what();	
	}
}