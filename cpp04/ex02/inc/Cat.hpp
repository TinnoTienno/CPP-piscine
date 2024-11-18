/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:49:45 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:58:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat&);
		~Cat();
		Cat& operator=(const Cat&);

		void		makeSound() const;
		std::string	getIdea(const int) const;
		void		setIdea(const int, const std::string);
	private :
		Brain *brain;
}	;
#endif