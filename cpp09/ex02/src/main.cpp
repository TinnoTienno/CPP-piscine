/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 15:58:54 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>

std::string buildString(char **args)
{
	std::string tmp = args[0];
	for (size_t i = 1; args[i]; i++)
		tmp += args[i];
	return tmp;
}
int main(int argc, char** argv)
{
	try
	{
		if (argc == 2)
			PmergeMe algo(argv[1]);
		else
			PmergeMe algo(buildString(&argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}