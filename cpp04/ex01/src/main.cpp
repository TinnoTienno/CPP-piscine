/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 17:42:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"
#include	<iostream>

int main()
{
	Animal	*Zoo[50];
	for (int i = 0; i < 25; i++)
		Zoo[i] = new Dog();
	for (int i = 25; i < 50; i++)
		Zoo[i] = new Cat();

	Zoo[2]
	for (int i = 0; i < 50; i++)
		delete (Zoo[i]);
}
