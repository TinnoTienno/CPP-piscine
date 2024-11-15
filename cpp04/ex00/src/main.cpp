/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 13:52:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"
#include	<iostream>

int main()
{
	{
		Animal *StinkyCat = new Cat;
		Cat	GrosMinet;
	
		GrosMinet.makeSound();
		StinkyCat->makeSound();
	}
	{
		WrongAnimal *StinkyCat = new WrongCat;
		WrongCat	GrosMinet;
	
		GrosMinet.makeSound();
		StinkyCat->makeSound(); // this guys actually doesnt know he is a cat
	}
}

