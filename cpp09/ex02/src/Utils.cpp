/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:31:42 by noda              #+#    #+#             */
/*   Updated: 2025/03/20 15:50:34 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "PmergeMeList.hpp"

std::string utoa(unsigned int nb)
{
	std::stringstream ss;
	ss << nb;
	return ss.str();
}

float	getTime()
{
	clock_t t;
	t = clock();
	return ((float) t )/CLOCKS_PER_SEC;
}

unsigned int getJacob(const unsigned int &nb)
{
	if (nb > 16)
		throw std::runtime_error("Can't find this Jacobsthal number");
	unsigned int array[16] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};

	return array[nb];
}

void	printList(std::list<unsigned int> list)
{
	std::list<unsigned int>::iterator iter = list.begin();
	for (size_t i = 0; i < list.size(); i++)
	{
		std::cout << *iter << " | ";
		std::advance(iter, 1);
	}
	std::cout << std::endl;
}

void	printVec(std::vector<unsigned int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " | ";
	std::cout << std::endl;
}
