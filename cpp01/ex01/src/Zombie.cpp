/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:52:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	this->m_name = "default";
}

Zombie::Zombie(std::string str)
{
	this->m_name = str;
}

Zombie::~Zombie()
{
	std::cout << this->m_name << ": Sleeeeeeep..." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set(std::string str) { this->m_name = str; }