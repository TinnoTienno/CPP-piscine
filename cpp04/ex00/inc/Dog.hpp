/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:49:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:26 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		
		void	makeSound(void) const;
}	;
#endif