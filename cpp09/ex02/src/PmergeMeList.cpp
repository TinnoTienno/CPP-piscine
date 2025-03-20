/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:14 by noda              #+#    #+#             */
/*   Updated: 2025/03/20 14:55:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeList.hpp"
#include "Utils.hpp"
#include <stdlib.h>
#include "ListIterator.hpp"
#include <math.h>

PmergeMeList::PmergeMeList() { }

PmergeMeList::PmergeMeList(const std::string &list)
{
	size_t i = 0;
	m_starttime = clock();
	while (i != list.npos)
	{
		std::string word = list.substr(i, list.find(' ', i) - i);
		if (list.find(' ', i) != list.npos)
			i = list.find(' ', i) + 1;
		else
			i = list.npos;
		m_list.push_back(atoi(word.c_str()));
	}
}

size_t		PmergeMeList::getSize()
{
	return m_list.size();
}


std::string PmergeMeList::print() const
{
	std::string res = "";
	for (std::list<unsigned int>::const_iterator iter = m_list.begin(); iter != m_list.end(); iter++)
			res += " " + utoa(*iter);
		res += "\n";
	return res;
}

void		PmergeMeList::mergeSort(size_t &level)
{
	if (m_list.size() < level * 2)
		return ;
	ListIterator iter1(m_list, 0, level);
	ListIterator iter2(m_list, 1, level);
	bool	end = false;
	while (!end)
	{
		if (iter1.getValue() > iter2.getValue())
			iter1.swap(iter2);
		end = iter1 + 2;
		end = iter2 + 2;
	}
	level *= 2;
	mergeSort(level);
}

void		PmergeMeList::oddFill(std::list<unsigned int> &odd, size_t level)
{
	int modulo = ((m_list.size() - level) % (level * 2));
	std::list<unsigned int>::iterator iter = m_list.end();
	std::advance(iter, - modulo);
	odd.splice(odd.end(), m_list, iter, m_list.end());
}

void		PmergeMeList::pendFill(std::list<unsigned int> &pend, size_t level)
{
	if (m_list.size() < level * 3)
		return ;
	std::list<unsigned int>::iterator iter1 = m_list.begin();
	std::advance(iter1, (level * 2));
	std::list<unsigned int>::iterator iter2 = iter1;
	std::advance(iter2, level);
	for (size_t i = 2; i * level < m_list.size(); i++)
	{
		pend.splice(pend.end(), m_list, iter1, iter2);
		iter1 = iter2;
		std::advance(iter2, level * 2);
		std::advance(iter1, level);
	}
}

std::list<unsigned int>::iterator PmergeMeList::binarySearch(unsigned int value, std::list<unsigned int>::iterator lowerbound, std::list<unsigned int>::iterator higherbound, size_t level)
{
	
	while (lowerbound != higherbound)
	{
		std::list<unsigned int>::iterator mid = lowerbound;
		std::advance(mid, (((std::distance(lowerbound, higherbound) / level)) / 2) * level);
		if (value > *higherbound)
		{
			std::advance(higherbound, + 1);
			return higherbound;
		}
		else if (value < *lowerbound)
		{
			std::advance(lowerbound, - level + 1);
			return lowerbound;
		}
		if (*mid == value)
		{
			std::advance(mid, 1);	
			return mid;
		}
		if (*mid > value)
			higherbound = mid;
		else
		{
			lowerbound = mid;
			if (std::distance(lowerbound, higherbound) / level == 1)
				break ;
			std::advance(lowerbound, level);	
		}
	} 
	std::advance(lowerbound, 1);
	return lowerbound;
}

std::list<unsigned int>::iterator PmergeMeList::higherBound(unsigned int i, size_t level)
{
	std::list<unsigned int>::iterator res = m_list.begin();
	size_t offset = getJacob(i) + getJacob(i - 1) - 1;
	std::advance(res, offset * level - 1);
	return res;
}

void 		PmergeMeList::jacobsthalSort(std::list<unsigned int> &pend, size_t level)
{
	unsigned int NbofInsert = (getJacob(3) - getJacob(3 - 1));
	for (unsigned int i = 3; (getJacob(i) - getJacob(i - 1)) * level <= pend.size(); i++)
	{
		NbofInsert = (getJacob(i) - getJacob(i - 1));
		for (;NbofInsert > 0; NbofInsert--)
		{
			std::list<unsigned int>::iterator end = pend.begin();
			std::advance(end, (NbofInsert) * level - 1);
			std::list<unsigned int>::iterator higherbound = higherBound(i, level);
			std::list<unsigned int>::iterator position = binarySearch(*end, ListIterator(m_list, 0, level).getIterator(), higherbound, level);
			std::list<unsigned int>::iterator begin = end;
			std::advance(begin, - level + 1);
			std::advance(end, 1);
			m_list.splice(position, pend, begin, end);
		}
	}
}

void		PmergeMeList::Insertion(std::list<unsigned int> &list, size_t level)
{
	while (list.size() >= level)
	{
		std::list<unsigned int>::iterator iter = list.begin();
		std::advance(iter, level - 1);
		std::list<unsigned int>::iterator end = m_list.end();
		std::advance(end, -1);
		std::list<unsigned int>::iterator position = binarySearch(*iter, ListIterator(m_list, 0, level).getIterator(), end, level);
		std::list<unsigned int>::iterator begin = iter;
		std::advance(begin, - level + 1);
		std::advance(iter, 1);
		
		m_list.splice(position, list, begin, iter);
	}
	
}

void		PmergeMeList::binaryInsertionSort(size_t &level)
{
	level /= 2;
	if (level == 0)
		return ;
	std::list<unsigned int> pend;
	std::list<unsigned int> odd;
	oddFill(odd, level);
	pendFill(pend, level);
	jacobsthalSort(pend, level);
	Insertion(pend, level);
	Insertion(odd, level);
	m_list.splice(m_list.end(), odd, odd.begin(), odd.end());
	binaryInsertionSort(level);
}

PmergeMeList::~PmergeMeList()
{

}