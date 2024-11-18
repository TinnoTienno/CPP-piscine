/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:13:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:44:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ScavTrap;

class ClapTrap
{
	protected :
		std::string 	m_name;
		int				m_hitPoint;
		int				m_energyPoint;
		int				m_attackDamage;
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
		void	print() const;
}	;

#endif