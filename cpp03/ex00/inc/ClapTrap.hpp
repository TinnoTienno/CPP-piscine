/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:13:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:30:57 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap // we haven't build the setters and getters but we'll need them for last exercice
{
	private :
		std::string m_name;
		int			m_hitPoint;
		int			m_energyPoint;
		int			m_attackDamage;
	public :
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap &operator =(const ClapTrap&);
		~ClapTrap();
		
		void	attack(const std::string&);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif