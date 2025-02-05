/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:14 by noda              #+#    #+#             */
/*   Updated: 2025/02/06 00:31:34 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeList.hpp"
#include "Utils.hpp"
#include <stdlib.h>
#include "ListIterator.hpp"
#include "MainIterator.hpp"
#include "PendIterator.hpp"

PmergeMeList::PmergeMeList() { }

PmergeMeList::PmergeMeList(const std::string &list)
{
	size_t i = 0;
	
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


std::string PmergeMeList::print() const
{
	std::string res = "LIST --> \n";
	for (std::list<unsigned int>::const_iterator iter = m_list.begin(); iter != m_list.end(); iter++)
			res += " | " + utoa(*iter);
		res += " |\n";
	return res;
}


/*
| | | | | | | | |
 0 1 2 3 4 5 6 7 
1a b a b a b a b  
2a   b   a   b  
4a       b
*/  

void		PmergeMeList::mergeSort(size_t &level)
{
	if (m_list.size() < level * 2)
		return ;
	ListIterator iter1(m_list, 0, level);
	ListIterator iter2(m_list, 1, level);
	bool	end = false;
	while (!end)
	{
		{
			if (iter1.getValue() > iter2.getValue())
				iter1.swap(iter2);
			end = iter1 + 2;
			end = iter2 + 2;
		}
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

void		PmergeMeList::binaryInsertionSort(size_t &level)
{
	if (level == 0)
		return ;
	std::list<unsigned int> pend;
	std::list<unsigned int> odd;
	oddFill(odd, level);
	std::cout << "odd" << std::endl;
	std::list<unsigned int>::iterator iterOdd = odd.begin();
	for (size_t i = 0; i < odd.size(); i++)
	{
		std::cout << " | " << *iterOdd;
		std::advance(iterOdd, 1);	
	}
	std::cout << std::endl;
	std::cout << *this << std::endl;
	pendFill(pend, level);
	std::cout << "pend" << std::endl;
	std::list<unsigned int>::iterator iter = pend.begin();
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::cout << " | " << *iter;
		std::advance(iter, 1);	
	}
	std::cout << std::endl;
	// jacobsthalSort(main, pend);
	level /= 2;
	std::cout << *this << std::endl;
	binaryInsertionSort(level);
}

void		PmergeMeList::sort()
{
	size_t level = 1;
	mergeSort(level);
	level /= 2;
	std::cout << *this << std::endl;
	binaryInsertionSort(level);
}

PmergeMeList::~PmergeMeList()
{

}