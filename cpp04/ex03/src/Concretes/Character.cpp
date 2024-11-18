/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:00:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:54:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < 4; i++)
		Inventory[i] = NULL;
	name = "Default";
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &obj)
{
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		Inventory[i] = NULL;
	name = "Default";
	*this = obj;
}

Character::Character(const std::string str)
{
	// std::cout << "Character string constructor called" << std::endl;
	name = str;
	for (int i = 0; i < 4; i++)
		Inventory[i] = NULL;
}

Character& Character::operator=(const Character &obj)
{
	std::cout << "Character copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		if (Inventory[i])
		{
			delete (Inventory[i]);
			Inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (obj.Inventory[i])
			Inventory[i] = obj.Inventory[i]->clone();
	}
	return *this;
}

void Character::cleanFloor()
{
	AMateria *tmp;
	
	while (this->floor)
	{
		std::cout << "cleaning floor : " << this->floor->getType() << std::endl;
		tmp = this->floor->next;
		delete (this->floor);
		this->floor = tmp;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (Inventory[i])
			delete (Inventory[i]);
	}
	cleanFloor();
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const {	return (name);	}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
	{
		std::cout << name << " couldnt equip the materia." << std::endl;
		return ;
	}
	while (i < 4 && Inventory[i])
		i++;
	if (i < 4)
	{
		Inventory[i] = m;
		std::cout << name << " equipped " << m->getType() << " materia" << std::endl;
	}
	else
		std::cout << name << " couldnt equip the materia." << std::endl;
}

void	Character::dropToFloor(AMateria *materia)
{
	AMateria *tmp;
	
	std::cout << "drop to floor : " << materia->getType() << std::endl;
	tmp = this->floor;
	materia->next = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		this->floor = materia;
	else
		tmp->next = materia;
}
void Character::unequip(int idx)
{
	if (idx > 4 || idx < 0 || !Inventory[idx])
	{
		std::cout << name << " tried to unequip a materia but couldnt find it" << std::endl;
		return ;
	}
	std::cout << name << " unequipped " << Inventory[idx]->getType() << " materia." << std::endl;
	dropToFloor(Inventory[idx]);
	Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "No materia to use" << std::endl;
		return ;
	}
	if (Inventory[idx])
		Inventory[idx]->use(target);
	else
		std::cout << "No materia to use" << std::endl;
}


