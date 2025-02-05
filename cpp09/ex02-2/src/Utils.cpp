/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:31:42 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 23:34:36 by noda             ###   ########.fr       */
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
	return ((float)t)/CLOCKS_PER_SEC;
}

void	swap(unsigned int *n1, unsigned int *n2)
{
	std::cout << *n1 << " " << *n2 << std::endl;
	*n1 += *n2;
	*n2 = *n1 - *n2;
	*n1 -= *n2;
	std::cout << *n1 << " " << *n2 << std::endl;
}

unsigned int getJacob(const unsigned int &nb)
{
	if (nb > 16)
		throw std::runtime_error("Cant find this Jacobsthal number");
	unsigned int array[16] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};

	return array[nb];
}