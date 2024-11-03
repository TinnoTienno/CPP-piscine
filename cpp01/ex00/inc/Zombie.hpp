/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:27:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:19:20 by eschussl         ###   ########.fr       */
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
		Zombie(std::string);
		~Zombie();
		void announce(); // Btw announce() = announce(void)
};

#endif