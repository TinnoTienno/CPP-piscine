/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:24:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 14:42:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

RPN::RPN()
{
	// std::cout << "RPN default constructor called" << std::endl;
}


static e_token findToken(char arg)
{
	if (isdigit(arg))
		return DIGIT;
	else if (arg == '+' || arg == '-' || arg == '*' || arg == '/')
		return OPERATOR;
	return UNDEFINED;
}

static e_operator findOpe(char arg)
{
	if (arg == '+')
		return ADD;
	else if (arg == '-')
		return SUBSTRACT;
	else if (arg == '*')
		return MULTIPLY;
	else if (arg == '/')
		return DIVIDE;
	return (OTHER);
}

RPN::RPN(char *args)
{
	m_res = 0;
	for (size_t i = 0; args[i]; i++)
	{
		if (args[i + 1] && args[i + 1] != ' ')
			throw (WrongInputException(args));
		e_token Tok = findToken(args[i]);
		switch (Tok)
		{
			case DIGIT:
				m_vals.push((float) atoi(&args[i]));
				break ;
			case OPERATOR:
				compute(findOpe(args[i]));
				break ;
			case UNDEFINED:
				throw (WrongInputException(&args[i]));
				break ;
		}
		if (args[i + 1])
			i++;
	}
	if (m_vals.size() != 1)
		throw (std::runtime_error("format : ./RPN number number operator"));
	m_res = m_vals.top();
	m_vals.pop();
	// std::cout << "RPN tab constructor called" << std::endl;
}

RPN::RPN(const RPN &obj)
{
	*this = obj;
	// std::cout << "RPN copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN &obj)
{
	this->m_vals = obj.m_vals;
	this->m_res = obj.m_res;
	// std::cout << "RPN copy assignement operator called" << std::endl;
	return (*this);
}

RPN::~RPN()
{
	while (!this->m_vals.empty())
		m_vals.pop();
}
	
float RPN::getRes() const { return m_res; }

void RPN::compute(const e_operator &oper)
{
	if (m_vals.size() < 2)
		throw (std::runtime_error("format : ./RPN number number operator"));
	float val1 = m_vals.top();
	m_vals.pop();
	float val2 = m_vals.top();
	m_vals.pop();
	switch (oper)
	{
	case ADD:
		m_vals.push(val1 + val2);
		break;
	case SUBSTRACT:
		m_vals.push(val2 - val1);
		break;
	case MULTIPLY:
		m_vals.push(val1 * val2);
		break;
	case DIVIDE:
		m_vals.push(val2 / val1);
		break;
	case OTHER:
		throw (std::runtime_error("format : ./RPN number number operator"));
	}
}

RPN::WrongInputException::WrongInputException(const char *arg) : m_arg(arg) { }

const char *RPN::WrongInputException::getArg() const { return m_arg; }

const char* RPN::WrongInputException::what() const throw()
{
	return ("Error: RPN::WrongInputException: ");
}

RPN::WrongInputException::~WrongInputException() throw() { }