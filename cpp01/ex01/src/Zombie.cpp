/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:19:44 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	_name = "default";
}

Zombie::Zombie(std::string str)
{
	_name = str;
}

Zombie::~Zombie()
{
	std::cout << _name << ": Sleeeeeeep..." << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set(std::string str)
{
	_name = str;
}