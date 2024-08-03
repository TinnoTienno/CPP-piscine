/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 13:56:06 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	Weapon		*weapon;
	std::string	name;
	public :
		void	attack(); 	
		HumanB (std::string str) : weapon(NULL), name(str) { };
		void	setWeapon(Weapon & );
		// ~HumanB();
};