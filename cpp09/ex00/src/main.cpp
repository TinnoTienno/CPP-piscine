/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:56 by eschussl          #+#    #+#             */
/*   Updated: 2025/03/20 14:27:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("format : ./btc file");
		std::ifstream ifs(argv[1], std::ifstream::in);
		if (ifs.fail())
			throw std::runtime_error("Could not open file");
		std::ifstream dfs("data.csv", std::ifstream::in);
		if (dfs.fail())
			throw std::runtime_error("Could not open datafile");
		BitcoinExchange btc(dfs, ifs);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}