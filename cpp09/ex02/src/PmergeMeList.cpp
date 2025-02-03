/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:14 by noda              #+#    #+#             */
/*   Updated: 2025/02/01 12:54:55 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeList.hpp"
#include "Utils.hpp"
#include <stdlib.h>

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

static void	swap(std::list<unsigned int>::iterator iter1, size_t ksize)
{
	std::list<unsigned int>::iterator iter2 = iter1;
	std::advance(iter2, ksize);
	for (size_t i = 0; i < ksize; i++)
	{
		*iter1 += *iter2;
		*iter2 = *iter1 - *iter2;
		*iter1 -= *iter2;
		std::advance(iter1, 1);
		std::advance(iter2, 1);
	}
}

void	PmergeMeList::pairSort(size_t ksize)
{
	if (ksize > m_list.size() / 2)
		return ;
	std::list<unsigned int>::iterator iter1 = m_list.begin();
	size_t i1 = 0;
	std::list<unsigned int>::iterator iter2 = iter1;
	std::advance(iter2, ksize);
	size_t i2 = ksize;
	while (i1 < m_list.size() && i2 < m_list.size())
	{
		if (*iter1 > *iter2)
			swap(iter1, ksize);
		std::advance(iter1, ksize * 2);
		i1 += ksize * 2;
		std::advance(iter2, ksize * 2);
		i2 += ksize * 2;
	}
	pairSort(ksize * 2);
}

/*
| | | | | | | | |
 0 1 2 3 4 5 6 7 
1a b a b a b a b  
2a   b   a   b  
4a       b
*/  

PmergeMeList::~PmergeMeList()
{

}