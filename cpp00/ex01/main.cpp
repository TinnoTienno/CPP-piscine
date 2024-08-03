/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:56:42 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 15:54:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::string line;
	PhoneBook book;
	
	while (1)
	{
		if (!std::getline(std::cin, line))
			break;
		if (!line.compare("EXIT"))
			return (0);
		else if (!line.compare("ADD"))
			book.add_cont();
		else if (!line.compare("SEARCH"))
			book.display();
	}
	return (0);
}
