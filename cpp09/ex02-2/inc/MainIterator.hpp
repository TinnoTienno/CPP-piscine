/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:42:58 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 22:58:12 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINITERATOR_HPP
#define MAINITERATOR_HPP
#include <list>
#include <iostream>

class MainIterator
{
	private :
		std::list<unsigned int>				&m_list;
		int									m_index; // position inside the global list
		std::list<unsigned int>::iterator	m_iter;
		const int							m_level;
		int									m_pos; // position inside main
		int									m_start; //position after which you should increment twice
	public :
		MainIterator(std::list<unsigned int> &list, int i, int level);
		bool 								operator++(int);
		bool 								operator--(int);
		bool								operator+(int value);
		bool								operator-(int value);
		const unsigned int					&getValue();
		const int 							&getIndex();
		const int 							&getPos();
}	;

std::ostream &operator<<(std::ostream &os, const MainIterator &obj);

#endif