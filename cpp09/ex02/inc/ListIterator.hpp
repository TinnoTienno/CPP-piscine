/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:22:27 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 20:54:20 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP
#include <list>
#include <iostream>

class ListIterator
{
	private :
		std::list<unsigned int>				&m_list;
		const int							m_level;
		std::list<unsigned int>::iterator	m_iter;
		int									m_index;
	public :
		ListIterator(std::list<unsigned int> &list, int i, int level);
		bool 								operator++(int);
		bool 								operator--(int);
		bool								operator+(int value);
		bool								operator-(int value);
		const unsigned int					&getValue();
		const int 							&getIndex();
		std::list<unsigned int>::iterator	&getIterator();

		void								swap(ListIterator &obj);
}	;


#endif