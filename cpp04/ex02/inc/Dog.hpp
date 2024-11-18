/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:49:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:58:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog& operator=(const Dog&);
		
		void		makeSound(void) const;
		std::string	getIdea(const int) const;
		void		setIdea(const int, const std::string);
	private :
		Brain *brain;
}	;
#endif