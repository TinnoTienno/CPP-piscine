/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:41:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:02:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "format : ./Harl2.0 Request" << std::endl;
		return 1;
	}
	Harl harly;
	harly.complain(argv[1]);
}