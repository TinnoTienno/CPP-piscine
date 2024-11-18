/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:33:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:38:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Purge.hpp"
#include "Fireball.hpp"
#include "Pyroblast.hpp"
#include <iostream>

AMateria *Character::floor = NULL;


int	main()
{
	IMateriaSource *test1S = new MateriaSource();
	Ice *Ice1 = new Ice;
	Cure *Cure1 = new Cure;
	Fireball *Fireball1 = new Fireball;
	Purge *Purge1 = new Purge;
	Pyroblast *Pyroblast1 = new Pyroblast;
	test1S->learnMateria(Ice1);
	test1S->learnMateria(Cure1);
	test1S->learnMateria(Fireball1);
	test1S->learnMateria(Purge1);
	test1S->learnMateria(Pyroblast1); //Cant learn more than 4 materia
	delete (Pyroblast1); // have to delete it manually
	AMateria *tmp1 = test1S->createMateria("ice");
	ICharacter *John = new Character("John");
	John->equip(tmp1); // dont need to delete it manually from now
	John->unequip(0); // ice is dropped on the floor then clean when ~Character
	Character Rob("Rob");
	AMateria *tmp2 = test1S->createMateria("cure");
	Rob.equip(tmp2);
	Rob.use(0, *John);
	Rob.unequip(0);
	tmp1 = test1S->createMateria("fireball");
	John->equip(tmp1);
	John->unequip(0);
	delete(test1S); // will delete every Materia that was learnt 
	delete(John); // will delete the materias dropped so far
}