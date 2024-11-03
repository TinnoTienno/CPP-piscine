/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:20:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private : 
		Weapon		*_weapon;
		std::string	_name;
	public :
		HumanB (std::string);
		void	attack(); 	
		void	setWeapon(Weapon*);
		void	setWeapon(Weapon&);
		// ~HumanB();
};