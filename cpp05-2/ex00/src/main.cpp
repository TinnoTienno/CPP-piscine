/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:09:10 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 17:16:59 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	

	
}