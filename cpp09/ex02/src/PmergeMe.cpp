/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:32 by eschussl          #+#    #+#             */
/*   Updated: 2025/03/20 15:16:28 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>

#include <unistd.h>
PmergeMe::PmergeMe() { 
}

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
	ss << std::fixed << std::setprecision(6) << static_cast<double>(m_endtime - m_starttime) / CLOCKS_PER_SEC<< "s"; ;
	return ss.str();
}

void				PmergeMe::setDuration()
{
	clock_t current_time = clock();
	m_endtime = current_time;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj)
{
	os << obj.print();
	return os;
}

void		PmergeMe::sort()
{
	size_t level = 1;
	m_starttime = clock();
	mergeSort(level);
	binaryInsertionSort(level);
	setDuration();
}