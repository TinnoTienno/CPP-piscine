/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:12:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:32:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		
		void highFivesGuys(void);
};
	
#endif