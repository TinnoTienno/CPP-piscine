/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:54:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	// std::cout << "MateriaSource default constructor called" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = NULL;
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}
MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	// std::cout << "MateriaSource copy assignement operator called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = obj.Inventory[i];
	return *this;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete (Inventory[i]);
	std::cout << "MateriaSource destructor called" << std::endl;
}
void 		MateriaSource::learnMateria(AMateria *M)
{
	int i = 0;
	while (i < 4 && Inventory[i])
		i++;
	if (i == 4)
	{
		std::cout << "Maetria source cant learn more than 4 Materia" << std::endl;
		return ;
	}
	Inventory[i] = M;
	std::cout << "Materia of type " << M->getType() << " was learnt." << std::endl;
}

AMateria* 	MateriaSource::createMateria(const std::string &type)
{
	AMateria *res;
	
	int i = 3;
	while (i >= 0)
	{
		if (Inventory[i] && Inventory[i]->getType() == type)
		{
			res = Inventory[i]->clone();
			std::cout << "Materia of type " << type << " has been created" << std::endl;
			return (res);
		}
		i--;
	}
	std::cout << "Could'nt create the materia " << type << ". Got to learn it first" << std::endl;
	return (NULL);
}