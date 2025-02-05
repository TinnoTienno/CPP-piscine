/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainIterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:45:39 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 22:18:56 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MainIterator.hpp>

MainIterator::MainIterator(std::list<unsigned int> &list, int i, int level) : m_list(list), m_level(level)
{
	m_pos = i;
	m_iter = m_list.begin();
	std::advance(m_iter, (level * (i + 1)) - 1);
	m_index = (level * (i + 1)) - 1;
}

bool 								MainIterator::operator++(int)
{
	if ((m_pos == 0 && ((size_t) m_index + m_level > m_list.size())) || ((size_t) m_index + (m_level * 2) > m_list.size()))
	{
		return 1;
	}
	if (m_pos == 0)
	{
		m_index += m_level;	
		std::advance(m_iter, m_level);
	}
	else
	{
		m_index += m_level * 2;	
		std::advance(m_iter, m_level * 2);
	}
	m_pos++;
	return 0;
}

// bool 								MainIterator::operator--(int);

// bool								MainIterator::operator+(int value);
// bool								MainIterator::operator-(int value);
const unsigned int					&MainIterator::getValue()
{
	return *m_iter;
}

const int 							&MainIterator::getIndex()
{
	return m_index;
}

const int 							&MainIterator::getPos()
{
	return m_pos;
}