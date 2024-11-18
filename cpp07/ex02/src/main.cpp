/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:14:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 13:46:26 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	Array<int> tab(5);
	Array<int> tab2;

	try
	{
		std::cout << "tab : value 0 : " << tab[0] << std::endl;
	}
	catch (const Array<int>::IndexOutOfScopeException &e) //Array::IndexOutOfScopeException::IndexOutOfScopeException
	{
		std::cout << "Error Array::IndexOutOfScopeException, index : " << e.getVal() << std::endl;
	}
	try
	{
		tab[0] = 1;
		tab2 = tab;
		std::cout << "tab2.size : " << tab2.size() <<  std::endl;
		std::cout << "tab2 : value 0 : " << tab2[0] << std::endl;
	}
	catch(const Array<int>::IndexOutOfScopeException &e)
	{
		std::cout << "Error Array::IndexOutOfScopeException, index : " << e.getVal() << std::endl;
	}
	try
	{
		tab2[0] = 100;
		std::cout << "tab 2: value 0 : " << tab2[0] << std::endl;
		std::cout << "tab : value 0 : " << tab[0] << std::endl;
	}
	catch(const Array<int>::IndexOutOfScopeException &e)
	{
		std::cout << "Error Array::IndexOutOfScopeException, index : " << e.getVal() << std::endl;
	}
}