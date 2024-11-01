/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:42:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/01 14:12:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form		Resignation("Resignation", 155, 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Billy("Billy", 148);
		Form		Resignation("Resignation", 20, 12);
		Billy.signForm(Resignation);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}