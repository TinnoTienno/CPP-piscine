/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:23:21 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 15:54:16 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

PhoneBook::PhoneBook ()
{
	_size = 0;
	_head = NULL;
}

std::string	add_val(std::string question)
{
	std::string	res;
	
	while (1)
	{
		std::cout << "New Contact > " << question << std::endl;
		std::cout << "New Contact > ";
		if (!getline (std::cin, res))
			break;
		if (res[0] != 0)
			break;
	}
	return (res);
}
void PhoneBook::add_cont()
{
	std::string a;
	std::string b;
	std::string c;
	std::string d;
	std::string e;
	
	a = add_val("First name ?");
	b = add_val("Last name ?");
	c = add_val("Nick name ?");
	d = add_val("Phone number ?");
	e = add_val("Darkest secret ?");
	
	Contact *New = new Contact(a, b, c, d, e, _head, _size);
	_head = New;
	if (_size == 8)
	{
		Contact *tmp;
		int		index = 0;

		tmp = _head;
		while (tmp->next->next)
		{
			tmp->index = _size - index++;
			tmp = tmp->next;
		}
		delete (tmp->next);
		tmp->next = NULL;
	}
	else
		_size++;
}

void PhoneBook::display ()
{
	Contact *tmp;
	std::string res;
	
	tmp = _head;
	while (tmp)
	{
		tmp->print_cont();
		tmp = tmp->next;
	}
	std::cout << "Choose an index" << std::endl;
	getline(std::cin, res);
	int index = atoi(res.c_str());
	tmp = _head;
	while (tmp)
	{
		if (tmp->index == index)
		{
			tmp->display_info();
			return ;
		}
		tmp = tmp->next;
	}
	std::cout << "index not found" << std::endl;
}

PhoneBook::~PhoneBook()
{
	Contact *tmp;
	void	*next;

	tmp = _head;
	while (tmp)
	{
		next = tmp->next;
		delete (tmp);
		tmp = (Contact *) next;
	}
}