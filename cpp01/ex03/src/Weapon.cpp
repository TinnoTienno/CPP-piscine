/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:14:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 13:51:53 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

const std::string& Weapon::getType()
{
	const std::string &res = type;
	return (res);
}

void	Weapon::setType(std::string name)
{
	type = name;
}
