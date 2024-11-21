/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:32 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 15:58:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <ctime>

PmergeMe::PmergeMe() { std::invalid_argument("PmergeMe(): Not enough argument"); }

void PmergeMe::toList(const std::string &str)
{
	starttime = std::clock();
	(void) str;
	for (size_t i = 0; i < 100000; i++)
		std::cout << "yo" << std::endl;
	m_list_compute_time = (std::clock() - starttime) *1000;
	// std::cout << "val = " << m_list_compute_time - starttime << std::endl;
}

PmergeMe::PmergeMe(const std::string& str)
{
	toList(str);
	// toVector(str);
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	this->m_list = obj.m_list;
	this->m_vector = obj.m_vector;
	this->m_list_compute_time = obj.m_list_compute_time;
	this->m_vector_compute_time= obj.m_vector_compute_time;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	while (!m_list.empty())
		m_list.pop_back();
	while (!m_vector.empty())
		m_vector.pop_back();
}


void PmergeMe::printList() const
{
	
	for (std::list<unsigned int>::const_iterator iter = m_list.begin(); iter != m_list.end(); iter++)
		std::cout << *iter;
	std::cout << std::endl;
}

void PmergeMe::printVector() const
{
	for (std::vector<unsigned int>::const_iterator iter = m_vector.begin(); iter != m_vector.end(); iter++)
		std::cout << *iter;
	std::cout << std::endl;
}


void PmergeMe::printListCompTime() const
{
	std::cout << "Time to process a range of " << m_size << " elements with std::list : " << m_list_compute_time << "us" << std::endl; 
}

void PmergeMe::printVectorCompTime() const
{
	std::cout << "Time to process a range of " << m_size << " elements with std::vector : " << m_vector_compute_time << "us" << std::endl; 
	
}
