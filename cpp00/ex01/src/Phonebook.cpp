/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:44:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/21 16:52:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	_index = -1;
};
PhoneBook::~PhoneBook()
{
	
};
std::string prompt(std::string ask)
{
	std::string line;

	while (1)
	{
		std::cout << ask << std::endl;
		if (!std::getline(std::cin, line))
			break;
		if (line.size())
			return (line);
	}
	return (NULL);
}
int		IsOnlyDigits(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}
void	PhoneBook::Add()
{
	std::string s1 = prompt("First Name ?");
	std::string s2 = prompt("Last Name ?");
	std::string s3 = prompt("Nick Name ?");
	std::string s4;
	
	while (1)
	{
		s4 = prompt("Phone Number ?");
		if (IsOnlyDigits(s4))
			break ;
		std::cout << "Phone number must be digits only" << std::endl;
	}
	std::string s5 = prompt("Darkest secret ?");
	_index++;
	_Contacts[_index % 8].AddData(s1, s2, s3, s4, s5);
}
int IndexPrompt(int index)
{
	std::string line;
	int res;
	while (1)
	{
		std::cout << "Please select an index" << std::endl;
		if (!std::getline(std::cin, line))
			break;
		if (IsOnlyDigits(line))
		{
			res = atoi(line.c_str());
			if (res >= 0 && res <= index % 8)
				return (res);
		}
		std::cout << "Index is wrong" << std::endl;
	}
	return (0);
}
void	PhoneBook::Search()
{
	int	i = 0;
	
	if (_index == -1)
		return ;
	while (i <= _index && i < 8)
	{
		std::cout << "         " << i << "|";
		_Contacts[i].DisplayTab();
		i++;
	}
	_Contacts[IndexPrompt(_index)].Display();
}

