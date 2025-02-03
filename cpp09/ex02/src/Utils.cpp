/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:31:42 by noda              #+#    #+#             */
/*   Updated: 2025/02/01 12:27:47 by noda             ###   ########.fr       */
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

void	memswap(unsigned int *ptr1, unsigned int *ptr2, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		ptr1 = &ptr1[i];
		ptr2 = &ptr2[i];
		*ptr1 += *ptr2;
		*ptr2 = *ptr1 - *ptr2;
		*ptr1 -= *ptr2;
	}
}
