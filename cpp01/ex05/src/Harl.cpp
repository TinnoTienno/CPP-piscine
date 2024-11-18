/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:47:30 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 11:58:45 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
void	Harl::complain(std::string level)
{
	std::string str = " DEBUG INFO   WARNINGERROR";
	int i = str.find(level) / 7;
	if (i >= 0 && i < 4)
		(this->*function[i])(); // Do you get how it works ? I love this shit
}

Harl::Harl()
{
	this->function[0] = &Harl::debug;
	this->function[1] = &Harl::info;
	this->function[2] = &Harl::warning;
	this->function[3] = &Harl::error;
}