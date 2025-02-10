/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 07:40:11 by noda              #+#    #+#             */
/*   Updated: 2025/02/07 19:12:00 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVec.hpp"
#include "Utils.hpp"
#include <stdlib.h>
#include <math.h>
#include <algorithm>

PmergeMevec::PmergeMevec() { }
PmergeMevec::PmergeMevec(const std::string &vector)
{
	size_t i = 0;
	m_starttime = clock();
	while (i != vector.npos)
	{
		std::string word = vector.substr(i, vector.find(' ', i) - i);
		if (vector.find(' ', i) != vector.npos)
			i = vector.find(' ', i) + 1;
		else
			i = vector.npos;
		m_vector.push_back(atoi(word.c_str()));
	}
}

size_t		PmergeMevec::getSize() { return m_vector.size(); }
std::string PmergeMevec::print() const
{
	std::string res = "";
	for (std::vector<unsigned int>::const_iterator iter = m_vector.begin(); iter != m_vector.end(); iter++)
			res += " " + utoa(*iter);
		res += "\n";
	return res;
	
}

void		PmergeMevec::swap(size_t i1, size_t i2, size_t level) //swap to ranges of memory
{
	std::swap_ranges(m_vector.begin() + i1, m_vector.begin() + i1 + level, m_vector.begin() + i2);
}

void		PmergeMevec::mergeSort(size_t &level)
{
	if (m_vector.size() < level * 2)
		return ;
	for (size_t i = level - 1; i < m_vector.size() - level; i += level * 2)
	{
		if (m_vector[i] > m_vector[i + level])
			swap(i - level + 1, i + 1, level);
	}
	level *= 2;
	mergeSort(level);
}

void		PmergeMevec::binaryInsertionSort(size_t &level)
{
	level /= 2;
	if (level == 0)
		return ;
	std::vector<unsigned int> pend;
	std::vector<unsigned int> odd;
	oddFill(odd, level);
	pendFill(pend, level);
	jacobsthalSort(pend, level);
	Insertion(pend, level);
	Insertion(odd, level);
	m_vector.insert(m_vector.end(), odd.begin(), odd.end());
	odd.erase(odd.begin(), odd.end());
	// std::cout << "vector" << std::endl << *this ;
	binaryInsertionSort(level);
}

void		PmergeMevec::oddFill(std::vector<unsigned int> &odd, size_t level)
{
	int modulo = ((m_vector.size() - level) % (level * 2));
	odd.insert(odd.end(), m_vector.end() - modulo, m_vector.end());
	m_vector.erase(m_vector.end() - modulo, m_vector.end());
}

void		PmergeMevec::pendFill(std::vector<unsigned int> &pend, size_t level)
{
	if (m_vector.size() < level * 3)
		return ;
	for (size_t i = level * 2; i < m_vector.size(); i++)
	{
		pend.insert(pend.end(), m_vector.begin() + i, m_vector.begin() + i + level);
		m_vector.erase(m_vector.begin() + i, m_vector.begin() + i + level);
		i += level - 1;
	}
}
std::vector<unsigned int>::iterator PmergeMevec::binarySearch(unsigned int value, size_t lowerbound, size_t higherbound, size_t level)
{
	// std::cout << " | " << "binarySearch with value : " << value << std::endl;
	while (lowerbound < higherbound)
	{
		// std::cout << "lowerbound " << m_vector[lowerbound] << " higherbound " << m_vector[higherbound] << std::endl;
		size_t mid = lowerbound + ((higherbound - lowerbound) / level / 2 * level);
		if (value > m_vector[higherbound])
			return m_vector.begin() + higherbound + 1;
		else if (value < m_vector[lowerbound])
			return m_vector.begin() + lowerbound - level + 1;
		if (m_vector[mid] == value)
			return m_vector.begin() + mid + 1;
		if (m_vector[mid] > value)
			higherbound = mid;
		else
		{
			lowerbound = mid;
			if ((higherbound - lowerbound) / level == 1)
				break;
			lowerbound += level;
		}
	}
	return m_vector.begin() + lowerbound + 1;
}

void 		PmergeMevec::jacobsthalSort(std::vector<unsigned int> &pend, size_t level)
{
	unsigned int NbofInsert = (getJacob(3) - getJacob(3 - 1));
	// std::cout << std::endl << "Jacobsthal : " << std::endl;
	// std::cout << "pend :" << std::endl;
	// printVec(pend);
	// std::cout << "vector :" << std::endl << *this;
	for (unsigned int i = 3; (getJacob(i) - getJacob(i - 1)) * level <= pend.size(); i++)
	{
		NbofInsert = (getJacob(i) - getJacob(i - 1));
		// std::cout << "NbofInsert : " << NbofInsert << std::endl;
		for (;NbofInsert > 0; NbofInsert--)
		{
			size_t higherbound = higherBound(i, level);
			std::vector<unsigned int>::iterator position = binarySearch(pend[(NbofInsert) * level - 1], level - 1, higherbound, level);
			// std::cout << "Inserting from " << *(pend.begin() + (NbofInsert - 1) * level) << std::cout << " to " << *(pend.begin() + (NbofInsert) * level - 1) << " at " << *position << std::endl;
			m_vector.insert(position, pend.begin() + (NbofInsert - 1) * level, pend.begin() + ((NbofInsert) * level));
			pend.erase(pend.begin() + (NbofInsert - 1) * level, pend.begin() + (NbofInsert) * level);
			// std::cout << "Jacobsthal : " << std::endl;
			// std::cout << "pend :" << std::endl;
			// printVec(pend);
			// std::cout << "vector :" << std::endl << *this;
		}
	}
}

size_t PmergeMevec::higherBound(unsigned int i, size_t level)
{
	return (getJacob(i) + getJacob(i - 1) - 1) * level - 1;
}

void		PmergeMevec::Insertion(std::vector<unsigned int> &vector, size_t level)
{
	// std::cout << std::endl << "classic insertion : " << std::endl;
	// std::cout << "source :" << std::endl;
	// printVec(vector);
	// std::cout << "vector :" << std::endl << *this;
	while (vector.size() >= level)
	{	
		std::vector<unsigned int>::iterator position = binarySearch(vector[level - 1], level - 1, m_vector.size() - 1, level);
		// std::cout << "Inserting normally from " << *(vector.begin()) << " to " << *(vector.begin() + level - 1) << std::endl;
		// std::cout << "Position in m_vector " << *position << std::endl;
		m_vector.insert(position, vector.begin(), vector.begin() + level);
		vector.erase(vector.begin(), vector.begin() + level);
		// std::cout << "classic insertion : " << std::endl;
		// std::cout << "source :" << std::endl;
		// printVec(vector);
		// std::cout << "vector :" << std::endl << *this;
	}
}

PmergeMevec::~PmergeMevec()
{
	
}