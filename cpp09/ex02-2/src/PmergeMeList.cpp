/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:14 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 22:14:27 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeList.hpp"
#include "Utils.hpp"
#include <stdlib.h>
#include "ListIterator.hpp"
#include "MainIterator.hpp"

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

void		PmergeMeList::binaryInsertionSort(size_t &level)
{
	if (level == 0)
		return ;
	MainIterator main(m_list, 0, level);
	PendIterator pend(m_list, 0, level);
	// while (!main++)
	// 	std::cout << "value : " << main.getValue() << std::endl;
	// PendIterator pend(m_list, 0, level);
	level /= 2;
	std::cout << *this << std::endl;
	binaryInsertionSort(level);
}

void		PmergeMeList::sort()
{
	size_t level = 1;
	mergeSort(level);
	std::cout << *this << std::endl;
	binaryInsertionSort(level);
}

PmergeMeList::~PmergeMeList()
{

}