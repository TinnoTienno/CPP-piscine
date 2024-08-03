/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/26 13:38:34 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string namez)
{
	name = namez;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void)
{
	std::cout << name << ": Sleeeeeeep..." << std::endl;
}
void	Zombie::set(std::string namez)
{
	name = namez;
}