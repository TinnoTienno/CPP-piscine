/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:45 by noda              #+#    #+#             */
/*   Updated: 2025/02/07 15:19:29 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
#include "PmergeMeVec.hpp"
#include <iostream>
#include <string>
#include <iomanip>

std::string buildString(char **args)
{
	std::string tmp = args[0];
	for (size_t i = 1; args[i]; i++)
		tmp += (std::string) " " + args[i];
	return tmp;
}

int main(int argc, char** argv)
{
		PmergeMe *algoVec;
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
		// std::cout << "Before: " ;
		// std::cout << *algoList << std::endl;
		algoList->sort();
		std::cout << "After: ";
		std::cout << *algoList << std::endl;
		std::cout << "Time to process a range of " << algoList->getSize() <<" elements with std::list : " << algoList->getDuration() << std::endl;
		if (argc == 2)
			algoVec = new PmergeMevec((std::string) argv[1]);
		else
			algoVec = new PmergeMevec(buildString(&argv[1]));
		// std::cout << "Before: " ;
		std::cout << *algoVec << std::endl;
		algoVec->sort();
		std::cout << "After: ";
		std::cout << *algoVec << std::endl;
		std::cout << "List: ";
		std::cout << *algoList << std::endl;
		std::cout << "Time to process a range of " << algoVec->getSize() <<" elements with std::vector : " << algoVec->getDuration() << std::endl;
		delete algoList;
		delete algoVec;
}