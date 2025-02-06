/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:45 by noda              #+#    #+#             */
/*   Updated: 2025/02/06 17:11:09 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
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
		clock_t start_vec = clock();
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
		std::cout << "Before: " ;
		std::cout << *algoList << std::endl;
		algoList->sort();
		clock_t end_vec = clock();
		double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << algoList->getSize()
              << " elements with std::vector: " << std::fixed << std::setprecision(6)
              << time_elapsed_vec << "s\n";
		std::cout << "Time to process a range of " << algoList->getSize() <<" elements with std::list : " << algoList->getDuration() << std::endl;
		std::cout << "After: ";
		std::cout << *algoList << std::endl;

		delete algoList;
}