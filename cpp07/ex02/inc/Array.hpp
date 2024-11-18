/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:15:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 18:03:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>
#include <iostream>
#include <ostream>

template <class T>

class Array
{
	private :
		T* 		_array;
		unsigned int 	_size;
	public :
		Array() 
		{
			std::cout << "Array default constructor called" << std::endl;
			_array = NULL;
			_size = 0;
		}
		Array(unsigned int n)
		{
			std::cout << "Array int constructor called" << std::endl;
			_array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_array[i] = 0;
			_size = n;
		}
		Array(const Array &obj)
		{
			std::cout << "Array copy constructor called" << std::endl;
			*this = obj;
		}
		Array& operator=(const Array &obj)
		{
			if (this->_array)
				delete[] (this->_array);
			std::cout << "size " << obj._size << std::endl;
			this->_array = new T[obj._size];
			try
			{
				for (unsigned int i = 0; i < obj.size(); i++)
				{
					std::cout << "obj[i] = " << obj[i] << std::endl;	
					(this[i]) = (obj[i]);
					// std::cout << "this[i] = " << this[i] << std::endl;	
				}
				_size = obj.size();
			}
			catch (IndexOutOfScopeException &e)
			{
				std::cout << "Error Array::IndexOutOfScopeException, index : " << e.getVal() << std::endl;
			}
			return (*this);
		}
		~Array()
		{
			if (this->_array)
				delete[] (_array);
		}
		
		unsigned int size() const { return (this->_size); }
		
		T&	operator[](unsigned int index)
		{
			if (index >= this->size())
				throw (IndexOutOfScopeException(index));
			return this->_array[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= this->size())
				throw (IndexOutOfScopeException(index));
			return this->_array[index];
		}
		class IndexOutOfScopeException : public std::exception
		{
			private :
				unsigned int _val;
			public :
				IndexOutOfScopeException(unsigned int value) { _val = value; }
				const unsigned int& getVal() const { return (_val); }
		}	;
}	;
#endif