/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:52:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 20:16:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"


void    Ice::use(ICharacter&target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

Ice& Ice::clone()
{
	Ice *res;

	res = new(Ice);
	return (res);
}