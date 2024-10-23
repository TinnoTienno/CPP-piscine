/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:23:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/22 15:26:53 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
static int	map_val(std ::string level)
{
	std::string tab[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4)
	{
		if (tab[i] == level)
			return (i);
		i++;
	}
	return (-1);
}
void	Harl::filter( std::string level)
{
	int mapVal = map_val(level);
        switch (mapVal)
        {
			default:
			{
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                break;
			}
            case (0):
            {
                debug();
                mapVal++;
            }
            case (1):
            {
                info();
                mapVal++;
            }
            case (2):
            {
                warning();
                mapVal++;
            }
            case (3):
            {
                error();
				mapVal++;
            }
        }
}
