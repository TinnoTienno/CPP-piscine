/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:12:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 17:57:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap &);
		~FragTrap();
		FragTrap& operator=(const FragTrap &);
		
		void highFivesGuys(void);
};
	
#endif