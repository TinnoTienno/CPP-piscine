/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:49:33 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private : 
		Weapon		*m_weapon;
		std::string	m_name;
	public :
		HumanB (std::string);
		void	attack(); 	
		void	setWeapon(Weapon*);
		void	setWeapon(Weapon&);
		// ~HumanB();
};