/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 14:33:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"
#include	<iostream>

int main()
{
	// Test sujet
	Animal	*Zoo[50];
	for (int i = 0; i < 25; i++)
		Zoo[i] = new Dog();
	for (int i = 25; i < 50; i++)
		Zoo[i] = new Cat();
	for (int i = 0; i < 50; i++)
		Zoo[i]->makeSound();
	for (int i = 0; i < 50; i++)
		delete (Zoo[i]);

	// Test copie profonde
	Dog	rex;
	rex.setIdea(0, "MANGEEEER");
	Dog	medor = rex;
	rex.setIdea(0, "DORMIRRRR");
	std::cout << "Medor : " << medor.getIdea(0) << std::endl;
	std::cout << "Rex : " << rex.getIdea(0) << std::endl;

}
