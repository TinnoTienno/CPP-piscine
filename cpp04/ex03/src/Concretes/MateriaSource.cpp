/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 19:47:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}
MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy assignement operator called" << std::endl;
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->Inventory[i] = obj.Inventory[i];
	return (*this);
}
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}
void 		MateriaSource::learnMateria(AMateria *M)
{
	int i = 0;
	while (i < 4 && Inventory[i])
		i++;
	if (i == 4)
		return ;
	Inventory[i] = M;
}

AMateria* 	MateriaSource::createMateria(const std::string &type)
{
	AMateria *res;
	
	int i = 3;
	while (i >= 0)
	{
		if (Inventory[i] && Inventory[i]->getType() == type)
		{
			res = Inventory[i];
			return (res);
		}
		i--;
	}
}