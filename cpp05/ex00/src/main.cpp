/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 16:56:25 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Bureaucrat John("John", 151);
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