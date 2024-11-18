/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:13:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:34:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ScavTrap;

class ClapTrap
{
	protected :		// protected otherwise we wouldnt be able to access it without a getter
		std::string m_name;
		int			m_hitPoint;
		int			m_energyPoint;
		int			m_attackDamage;
	public :
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap &);
		ClapTrap &operator=(const ClapTrap &);
		~ClapTrap();
		
		virtual void	attack(const std::string&); // we set the virtual keyword ofr 
		void	takeDamage(unsigned int amount); //Why is there no new takeDamage for ScavTrap
		void	beRepaired(unsigned int amount);
};

#endif