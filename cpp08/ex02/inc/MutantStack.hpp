/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:58:13 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 12:58:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	typedef std::stack<T> Stack;
	using Stack::c;
	public :
		using Stack::operator=;
		using Stack::size;
    	using Stack::push;
    	using Stack::pop;
    	using Stack::top;
		using Stack::iterator;
}	;

#endif