/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:58:13 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 17:17:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <class T>
class MutantStack : public std::stack
{
	class iterator
	{
		void	*pos;
		T		value;
		public :
			
	}	;
	iterator top() const;
	iterator begin() const;
	iterator end() const;
}	;

#endif