/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:32 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/31 13:16:04 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <ctime>
#include "Utils.hpp"
#include <sstream>

PmergeMe::PmergeMe() { m_starttime = getTime(); }

// PmergeMe::PmergeMe(const std::string& str) { }

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::string			PmergeMe::getDuration() const
{
	float current_time = getTime();
	std::stringstream ss;
	ss << current_time - m_starttime;
	return ss.str();
}


std::ostream &operator<<(std::ostream &os, const PmergeMe &obj)
{
	os << obj.print();
	return os;
}