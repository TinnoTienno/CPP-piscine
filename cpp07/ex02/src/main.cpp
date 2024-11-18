/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:14:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 17:48:25 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	Array<int> tab(5);

	try
	{
		std::cout << tab[3] << std::endl;
	}
	catch (std::exception &e) //Array::IndexOutOfScopeException::IndexOutOfScopeException
	{
		std::cout << "Error Array::IndexOutOfScopeException, index : " << std::endl;
	}
	
	tab[0] = 1;
	int i = tab[0] + 1;
	std::cout << i << std::endl;
	Array<int> tab2;
	tab2 = tab;
	// std::cout << tab2.size() <<  std::endl;
	// std::cout << tab2[0] << std::endl;
}