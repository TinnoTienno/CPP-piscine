/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:13:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:32:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ScavTrap;

class ClapTrap
{
	protected :
		std::string _name;
		int	_hitPoint;
		int	_energyPoint;
		int	_attackDamage;
	public :
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap&);
		~ClapTrap();
		
		void	attack(const std::string&);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif