/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:57:54 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <stdlib.h>

Contact::Contact(std::string a, std::string b, std::string c, std::string d, std::string e, void *ptr, int indexnum)
{
	_first_name = a;
	_last_name = b;
	_nick_name = c;
	_phonenumber = d;
	_secret = e;
	index = indexnum;
	next = (Contact *) ptr;
}
void	print_data(std::string str, std::string end)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << "." << end;
	else
	{
		unsigned long i = 11;
		while (--i > str.size())
			std::cout << " ";
		std::cout << str;
		std::cout << end;
	}
}
void Contact::print_cont()
{
	std::cout << "         " << index << "|";
	print_data(_first_name, "|");
	print_data(_last_name, "|");
	print_data(_nick_name, "\n");
}

void	Contact::display_info()
{
	std::cout << "First name :" << _first_name << std::endl;
	std::cout << "Last name :" << _last_name << std::endl; 
	std::cout << "Nick name :" << _nick_name << std::endl; 
	std::cout << "Phone number :" << _phonenumber << std::endl; 
	std::cout << "Darkest secret :" << _secret << std::endl; 
}