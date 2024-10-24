/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 15:05:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Character("Noda");
	ClapTrap Ennemy("Minion");

	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	Character.attack("Minion");
	Ennemy.takeDamage(2);
	Ennemy.beRepaired(1);
	ClapTrap newEnnemy;
	newEnnemy = Character;
	newEnnemy.attack("Noda");
	Character.takeDamage(2);
	Character.attack("Noda's shadow");
	newEnnemy.takeDamage(2);
}