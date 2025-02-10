/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PendIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:14:52 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 22:16:43 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENDITERATOR_HPP
#define PENDITERATOR_HPP
#include <list>
#include <iostream>

class PendIterator
{
	private :
		std::list<unsigned int>				&m_list;
		int									m_index; // position inside the global list
		std::list<unsigned int>::iterator	m_iter;
		const int							m_level;
		int									m_pos; // position inside pend
	public :
		PendIterator(std::list<unsigned int> &list, int i, int level);
		bool 								operator++(int);
		bool 								operator--(int);
		bool								operator+(int value);
		bool								operator-(int value);
		const unsigned int					&getValue();
		const int 							&getIndex();
		const int 							&getPos();
}	;
#endif