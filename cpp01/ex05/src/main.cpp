/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:41:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/09 15:37:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	err(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}
int main(int argc, char **argv)
{
	if (argc != 2)
		return (err("Arg error"));
	Harl harly;
	harly.complain(argv[1]);
}