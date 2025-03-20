/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:45 by noda              #+#    #+#             */
/*   Updated: 2025/02/13 16:57:18 by eschussl         ###   ########.fr       */
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
		std::string values;
		if (argc == 2)
			values = (std::string) argv[1];
		else
			values = buildString(&argv[1]);
		std::cout << "Before: " << values << std::endl;
		algoList = new PmergeMeList(values);
		algoList->sort();
		algoVec = new PmergeMevec(values);
		algoVec->sort();
		std::cout << "After: " << *algoVec << std::endl;
		std::cout << "Time to process a range of " << algoVec->getSize() <<" elements with std::vector : " << algoVec->getDuration() << std::endl;
		std::cout << "Time to process a range of " << algoList->getSize() <<" elements with std::list : " << algoList->getDuration() << std::endl;
		delete algoList;
		delete algoVec;
}