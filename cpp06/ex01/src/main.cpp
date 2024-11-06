/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 15:39:53 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data what;

	what.nb = 5;
	long adrs = Serializer::serialize(&what); 

	std::cout << adrs << std::endl;
	
	Data *ptr = Serializer::deserialize(adrs);
	std::cout << ptr->nb << std::endl;
}