/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:47:30 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 16:24:46 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

void	debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void	info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void	warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been comingfor years whereas you started working here since last month." << std::endl;
}
void	error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
void	complain( std::string level)
{
	std::string str_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		*func_arr[4] = {debug(), info, warning, error};
	int i = 0;
	
	while (i < 5)
	{
		if (level.compare(str_arr[i]))
		{
			func_arr[i];
			return ;
		}
		i++;
	}
}