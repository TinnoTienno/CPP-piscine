/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 17:11:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap Character("Noda");
	ScavTrap Ennemy("Minion");

	Character.attack("Minion");
	Ennemy.takeDamage(20);
	Ennemy.guardGate();
	Character.attack("Minion");
	Ennemy.takeDamage(10);
}