/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:09:10 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 18:55:24 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat pawn;
		std::cout << pawn << std::endl;
		pawn--;
		std::cout << pawn << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Viktor("Viktor", 1);
		std::cout << Viktor << std::endl;
		Viktor++;
		std::cout << Viktor << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Vladimir("Vladimir", 5);
		std::cout << Vladimir << std::endl;
		Vladimir++;
		std::cout << Vladimir << std::endl;\
		Vladimir--;
		std::cout << Vladimir << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------" << std::endl << "End of EX00 tests" << std::endl;
	try
	{
		Bureaucrat Vladimir("Vladimir", 5);
		Form		Workpermit;

		std::cout << Workpermit << std::endl;
		Vladimir.signForm(Workpermit);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Vladimir("Vladimir", 5);
		Form		Drivinglicence("Driving Licence", 55, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	
}