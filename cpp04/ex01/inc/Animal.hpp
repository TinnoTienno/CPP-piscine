/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 16:35:37 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
	public :
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		Animal& operator=(const Animal&);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
	protected :
		std::string	type;
}	;
#endif