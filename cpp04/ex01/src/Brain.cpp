/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:54:21 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:57:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "Emptiness";
	std::cout << "Default brain constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = b;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
Brain& Brain::operator= (const Brain &b)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this == &b)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return *this;
}

void Brain::setIdea(const int i, const std::string str) { ideas[i] = str; }

std::string Brain::getIdea(const int i) const { return ideas[i]; }