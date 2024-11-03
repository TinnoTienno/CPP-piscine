/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:14:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:21:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>


Weapon::Weapon(std::string str) : type(str) { }

const std::string& Weapon::getType() const
{
	const std::string &res = _type;
	return (res);
}

void	Weapon::setType(std::string str) { _type = str; }
