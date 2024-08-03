/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:11:56 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 13:52:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
		std::string	type;
	public :
		const std::string& getType();
		void setType( std::string );
		Weapon(std::string str) : type(str) { };
		// ~Weapon();
};

#endif