/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:17:42 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:20:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private :
		std::string	_name;
		Weapon&		_weapon;
	public :
		HumanA(std::string str, Weapon& new_weap);
		void	attack();
};