/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:15:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 18:22:34 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>

class Array
{
	private :
		T* array;
	public :
		Array() { array = (NULL); }
		Array(unsigned int n)
		{
			array = new 
		}
		Array(const Array &obj)
		{
			this->	
		}
		Array& operator=(const Array&);
		~Array();
	
}	;
#endif