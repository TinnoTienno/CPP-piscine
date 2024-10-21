/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:16 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/21 16:53:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	std::string	line;
	PhoneBook book;
	
	std::cout << "Welcome to the crappiest phonebook of all time" << std::endl;
	while (1)
	{
		std::cout << "Please select a command (ADD/SEARCH/EXIT)" << std::endl;
		if (!std::getline(std::cin, line))
			break;
		if (!line.compare("EXIT"))
			return (0);
		else if (!line.compare("ADD"))
			book.Add();
		else if (!line.compare("SEARCH"))
			book.Search();
		else
			std::cout << "Wrong Input" << std::endl;
	}
	return (1);
}