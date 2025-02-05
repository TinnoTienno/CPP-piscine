/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:45 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 20:57:27 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
#include <iostream>
#include <string>

std::string buildString(char **args)
{
	std::string tmp = args[0];
	for (size_t i = 1; args[i]; i++)
		tmp += (std::string) " " + args[i];
	return tmp;
}

int main(int argc, char** argv)
{
		PmergeMe *algoList;
		if (argc == 1)
		{
			std::cout << "format > ./PmergeMe.bin value1 valueN... || ./PmergeMe.bin \"value1 valueN...\"" << std::endl;
			return 1;
		}
		if (argc == 2)
			algoList = new PmergeMeList((std::string) argv[1]);
		else
			algoList = new PmergeMeList(buildString(&argv[1]));
		std::cout << *algoList << std::endl;
		algoList->sort();
		std::cout << "time since start : " << algoList->getDuration() << "s" << std::endl;

		delete algoList;
}