/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:32 by eschussl          #+#    #+#             */
/*   Updated: 2025/02/06 16:56:44 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>

PmergeMe::PmergeMe() { m_starttime = clock(); }

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
	std::stringstream ss;
	ss << std::fixed << std::setprecision(6) << m_duration << "s"; ;
	return ss.str();
}

#include <unistd.h>
void				PmergeMe::setDuration()
{
	clock_t current_time = clock();
	m_duration = static_cast<double>(current_time - m_starttime) / CLOCKS_PER_SEC;
}
std::ostream &operator<<(std::ostream &os, const PmergeMe &obj)
{
	os << obj.print();
	return os;
}