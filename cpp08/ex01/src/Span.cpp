/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:33:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 12:10:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <climits>


Span::Span()
{
	this->_arr.reserve(0);
	// std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
	this->_arr.reserve(N);
	// std::cout << "Span unsigned int constructor called" << std::endl;
}

Span::Span(const Span &obj)
{
	*this = obj;
	// std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &obj)
{
	if (this == &obj)
		return *this;
	this->_arr = obj._arr;
	this->_arr.reserve(obj._arr.capacity());
	// std::cout << "Span copy assignement operator called" << std::endl;
	return (*this);
}

Span::~Span()
{
	// std::cout << "Span destructor called" << std::endl;
}


void Span::addNumber(const int &n)
{
	// std::cout << "Capacity : " << this->_arr.capacity() << " | size : " << this->_arr.size() << std::endl;
	if (this->_arr.capacity() == this->_arr.size())
		throw (std::length_error("Span::addNumber:exception : too many push"));
	this->_arr.push_back(n);
}

int Span::shortestSpan(const int &n) const
{
	int current = INT_MAX;
	if (_arr.size() <= 1)
		throw (std::logic_error("Span::shorterSpan:exception : size too small"));
	for (std::vector<int>::const_iterator it = _arr.begin(); it != _arr.end(); it++)
	{
		if (n == *it)
			return (0);
		if (std::abs(n - *it) < current)
			current = std::abs(n - *it);
	}
	return current;
}

int Span::longestSpan(const int &n) const
{
	int current = 0;
	if (_arr.size() <= 1)
		throw (std::logic_error("Span::longestSpan:exception : size too small"));
	for (std::vector<int>::const_iterator it = _arr.begin(); it != _arr.end(); it++)
	{
		if (std::abs(n - *it) > current)
			current = std::abs(n - *it);
	}
	return current;
}

void Span::addRange(const unsigned int &range, int (*function)(int))
{
	for (unsigned int i = 0; i < range; i++)
		addNumber(function(i));
}

void Span::print() const
{
	std::cout << "SpanPrint :" << std::endl;
	for (std::vector<int>::const_iterator it = _arr.begin(); it != _arr.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "----" << std::endl;
}