/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:41 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 21:36:35 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListIterator.hpp"
#include <list>


ListIterator::ListIterator(std::list<unsigned int> &list, int i, int level) : m_list(list), m_level(level)
{
	m_iter = m_list.begin();
	m_index = (level * (i + 1)) - 1;
	std::advance(m_iter, (level * (i + 1)) - 1);

}

bool 								ListIterator::operator++(int)
{
	if ((size_t) m_index + m_level > m_list.size())
		return 1;
	m_index += m_level;
	std::advance(m_iter, m_level);
	return 0;
}

bool 								ListIterator::operator--(int)
{
	if (m_index -  m_level < 0)
		return 1;
	m_index -= m_level;
	std::advance(m_iter, -m_level);	
	return 0;
}

bool								ListIterator::operator+(int value)
{
	if ((size_t)m_index +  m_level * value > m_list.size() || m_index +  m_level < 0)
		return 1;
	m_index += m_level * value;
	std::advance(m_iter, m_level * value);
	return 0;
}
bool								ListIterator::operator-(int value)
{
	if ((size_t)m_index -  m_level * value > m_list.size() || m_index +  m_level < 0)
		return 1;
	m_index -= m_level * value;
	std::advance(m_iter, - (m_level * value));
	return 0;
}
const unsigned int					&ListIterator::getValue()
{
	return *m_iter;
}
const int 						&ListIterator::getIndex()
{
	return m_index;
}

static void							swapval(unsigned int &nb1, unsigned int &nb2)
{
	nb1 += nb2;
	nb2 = nb1 - nb2;
	nb1 -= nb2;
}

void								ListIterator::swap(ListIterator &obj)
{
	if (obj.getIndex() == this->getIndex())
		return;
	if (obj.m_level != this->m_level || obj.m_list != this->m_list)
		throw std::logic_error("Can't swap two different type of iterator");
	int t = 0;
	for (std::list<unsigned int>::iterator iter1 = m_iter, iter2 = obj.m_iter; t < m_level; t++)
	{
		swapval(*iter1, *iter2);
		std::advance(iter1, -1);
		std::advance(iter2, -1);
	}
}