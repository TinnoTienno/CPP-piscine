/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:31:48 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 18:50:16 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include <math.h>

ScalarConvert::ScalarConvert()
{
	std::cout << "ScalarConvert default constructor called" << std::endl;
}

ScalarConvert::ScalarConvert(const ScalarConvert&)
{
	std::cout << "ScalarConvert copy constructor called" << std::endl;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert&)
{
	std::cout << "ScalarConvert copy assignement operator called" << std::endl;
	return (*this);
}

ScalarConvert::~ScalarConvert()
{
	std::cout << "ScalarConvert destructor called" << std::endl;
}

bool IsOnlyDigit(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (0);
	}
	return (1);
}

bool HasPoint(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			return (1);
	}
	return (0);
}

Type Parse(const std::string &str)
{
	if (IsOnlyDigit(str))
	{
		if (HasPoint(str))
			return (Double);
		else
			return (Int);
	}
	else if (HasPoint(str) && str[str.size() - 1] == 'f')
		return (Float);
	else if (str.size() == 1)
		return (Char);
	else
		return (Other);
}
void ScalarConvert::Convert(const std::string &str)
{
	int num_int;
	float num_float;
	double num_double;
	switch (Parse(str))
	{
		case (Char) :
		std::cout << "char : " << str << std::endl;
		std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(str[0]) << ".0" << std::endl;
		std::cout << "double : " << static_cast<double>(str[0]) << ".0" << "f" << std::endl;;
		break ;
		
		case (Int) :
		num_int  = std::atoi(str.c_str());
		std::cout << "char : " << static_cast<char>(num_int) << std::endl;
		std::cout << "int : " << static_cast<int>(num_int) << std::endl;
		std::cout << "float : " << static_cast<float>(num_int) << ".0" << std::endl;
		std::cout << "double : " << static_cast<double>(num_int) << ".0" << "f" << std::endl;
		break ;
		
		case (Float) :
		num_float = (float) std::atof(str.c_str());
		std::cout << "char : " << static_cast<char>(num_float) << std::endl;
		std::cout << "int : " << static_cast<int>(num_float) << std::endl;
		std::cout << "float : " << static_cast<float>(num_float);
		if ((num_float - static_cast<int>(num_float)) == 0)
			std::cout << ".0";
		std::cout << std::endl;
		std::cout << "double : " << static_cast<double>(num_float);
		if ((num_float - static_cast<int>(num_float)) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		break ;
		
		case (Double) :
		num_double = std::atof(str.c_str());
		std::cout << "char : " << static_cast<char>(num_double) << std::endl;
		std::cout << "int : " << static_cast<int>(num_double) << std::endl;
		std::cout << "double : " << static_cast<double>(num_double);
		if ((num_double - static_cast<int>(num_double)) == 0)
			std::cout << ".0";
		std::cout << std::endl;
		std::cout << "float : " << static_cast<float>(num_double);
		if ((num_double - static_cast<int>(num_double)) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		break ;
		
		case (4) : 
		if (!(str.compare("-inff") || str.compare("-inff")))
		{
			std::cout << "char : " << "impossible" << std::endl;
			std::cout << "int : " << "impossible" << std::endl;
			std::cout << "float : " << str << std::endl;
			std::cout << "double : " << str << std::endl;
			
		}
	}
}
