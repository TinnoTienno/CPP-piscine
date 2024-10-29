/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:33:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/29 16:42:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
// #include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
int	main()
{
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// // src->learnMateria(new Cure());
	// // ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// // me->equip(tmp);
	// // tmp = src->createMateria("cure");
	// // me->equip(tmp);
	// // ICharacter* bob = new Character("bob");
	// // me->use(0, *bob);
	// // me->use(1, *bob);
	// // delete bob;
	// // delete (me);
	// // delete src;
	// // return 0;

	// Character Timmy("Timmy");
	// tmp = src->createMateria("ice");
	// Timmy.equip(tmp);
	// // Timmy.equip(tmp);
	// Character	Ralph("Ralph");
	// Ralph = Timmy;
	// Ralph.use(0, Timmy);
	// Ralph.unequip(0);
	// // Ralph.use(0, Timmy);
	// // tmp = src->createMateria("ice");
	// // tmp = src->createMateria("cure");
	// // Ralph.equip(tmp);
	// Ralph.use(0, Timmy);
	// Timmy.use(0, Ralph);
	// delete src;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		std::cout << std::endl;

		std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
		Character *dur0 = new Character("Alice");
		ICharacter *dur1 = new Character(*dur0);
		delete dur0;
		delete dur1;
		std::cout << std::endl;

		std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
		AMateria* tmp;
		ICharacter *dur2 = new Character("Alice");
		tmp = src->createMateria("ice");
		dur2->equip(tmp);
		tmp = src->createMateria("cure");
		dur2->equip(tmp);
		tmp = src->createMateria("hi");
		dur2->equip(tmp);
		delete src;
		std::cout << std::endl;

		std::cout << "4. Check maximum equipped too:" << std::endl;
		AMateria *cure = new Cure();
		AMateria *ice = new Ice();
		dur2->equip(cure);
		dur2->equip(cure);
		dur2->equip(ice);
		dur2->unequip(2);
		delete ice; // Ice must be deleted manually when unequipped
		dur2->unequip(2);
		dur2->unequip(6);
		std::cout << std::endl;

		std::cout << "5. Use materias on new chacarter:" << std::endl;
		ICharacter* bob = new Character("Bob");
		dur2->use(0, *bob);
		dur2->use(1, *bob);
		dur2->use(2, *bob);
		dur2->use(6, *bob);
		dur2->use(-4, *bob);
		dur2->use(3, *bob);
		delete bob;
		std::cout << std::endl;

		delete dur2;
		delete mat;
		return (0);
	}
}