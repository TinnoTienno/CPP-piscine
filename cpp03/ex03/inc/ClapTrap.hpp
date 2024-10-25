/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:13:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 14:39:07 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ScavTrap;

class ClapTrap
{
	protected :
		std::string name;
		int	hitPoint;
		int	energyPoint;
		int	attackDamage;
	public :
		ClapTrap();
		ClapTrap(const ClapTrap &);
		ClapTrap(std::string);
		~ClapTrap();
		ClapTrap &operator = (const ClapTrap &);
		
		void	setHP(void);
		void	setEP(void);
		void	setAD(void);
		void	attack(const std::string&);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif