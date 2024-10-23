/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:34:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/21 17:47:33 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void Contact::AddData(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5)
{
	_firstName = s1;
	_LastName = s2;
	_NickName = s3;
	_PhoneNumber = s4;
	_Secret = s5;
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
		std::cout << str << end;
	}
}
void	Contact::DisplayTab()
{
	print_data(_firstName, "|");
	print_data(_LastName, "|");
	print_data(_NickName, "\n");
}

void	Contact::Display()
{
	std::cout << "First Name :" << _firstName << std::endl;
	std::cout << "Last Name :" << _LastName << std::endl;
	std::cout << "Nick Name :" << _NickName << std::endl;
	std::cout << "Phone Number :" << _PhoneNumber << std::endl;
	std::cout << "Secret :" << _Secret << std::endl << std::endl;
}