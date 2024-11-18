/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:14:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:51:37 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>


Weapon::Weapon(std::string str) : m_type(str) { }

const std::string& Weapon::getType() const { return this->m_type; }

void	Weapon::setType(std::string str) { this->m_type = str; }
