/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:27:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:19:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private :
		std::string _name;
	public :
		Zombie(); // default constructor
		Zombie(std::string);
		~Zombie();
		
		void set(std::string);
		void announce ();
};

#endif