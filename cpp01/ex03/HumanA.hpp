/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:17:42 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 13:49:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	std::string	name;
	public :
		HumanA(std::string str, Weapon& new_weap) : name(str), weapon(new_weap){ };
		void	attack();
		Weapon&		weapon;
		// ~HumanA();
};