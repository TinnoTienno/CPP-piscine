/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PendIterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:17:09 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 22:28:38 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PendIterator.hpp"

PendIterator::PendIterator(std::list<unsigned int> &list, int i, int level) : m_list(list), m_level(level)
{
	m_pos = i;
	m_iter = m_list.begin();
	std::advance(m_iter, (level * (i + 3)) - 1);
	m_index = (level * (i + 3)) - 1;
	std::cout << "Pend start " << *m_iter << std::endl;
}

bool 								PendIterator::operator++(int)
{
	if (((size_t) m_index + m_level * 2 > m_list.size()))
		return 1;
	m_pos++;
	std::advance(m_iter, m_level * 2);
	m_index += m_level * 2;
	return 0;
}

// bool 								PendIterator::operator--(int);
// bool								PendIterator::operator+(int value);
// bool								PendIterator::operator-(int value);
const unsigned int					&PendIterator::getValue()
{
	return *m_iter;
}
const int 							&PendIterator::getIndex()
{
	return m_index;
}
const int 							&PendIterator::getPos()
{
	return m_pos;
}