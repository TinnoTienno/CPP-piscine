/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:21:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 12:06:50 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
	std::vector<int> _arr;
	public :
		Span();
		Span(unsigned int N);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();
		
		void addNumber(const int&);
		int shortestSpan(const int&) const;
		int longestSpan(const int&) const;
		void addRange(const unsigned int&, int (*function)(int));
		template <typename iterator>
		void fill(iterator begin, iterator end)
		{
			for (iterator it = begin ; it != end; it++)
				addNumber(*it);
		}
		std::vector<int>::iterator begin() { return (_arr.begin()); }
		std::vector<int>::iterator end() { return (_arr.end()); } 
		void print() const;
}	;
#endif