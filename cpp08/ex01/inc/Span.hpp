/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:21:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 16:32:37 by eschussl         ###   ########.fr       */
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
}	;
#endif