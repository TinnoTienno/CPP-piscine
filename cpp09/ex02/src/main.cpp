/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:37 by eschussl          #+#    #+#             */
/*   Updated: 2025/02/01 14:44:13 by noda             ###   ########.fr       */
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
	try
	{
		PmergeMe *algoList;
		if (argc == 2)
			algoList = new PmergeMeList((std::string) argv[1]);
		else
			algoList = new PmergeMeList(buildString(&argv[1]));
		std::cout << *algoList << std::endl;
		size_t ksize = 1;
		algoList->pairSort(ksize);
		std::cout << "time since start : " << algoList->getDuration() << "s" << std::endl;
		std::cout << *algoList << std::endl;

		delete algoList;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}