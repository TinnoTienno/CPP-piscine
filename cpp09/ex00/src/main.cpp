/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:56 by eschussl          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:24 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <iomanip>

std::string findkey(std::string &line)
{
	return line.substr(0, line.find(","));
}

float findval(std::string &line)
{
	std::string res = line.substr(line.rfind(",") + 1, line.size() - 1);
	return (float) atof(res.c_str());
}

void buildMap(std::ifstream &dfs, std::map<std::string,float> &data_map)
{
	std::string line;
	std::getline(dfs, line); //takes out the first line defining format
	while (1)
	{
		if (!std::getline(dfs, line))
			break;
		data_map.insert(std::make_pair(findkey(line), findval(line)));
	}
}

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789.-") == std::string::npos;
}
size_t	count(std::string val, char c)
{
	size_t res = 0;
	for (std::string::iterator it = val.begin(); it != val.end(); it++)
	{
		if (*it == c)
			res++;
	}
	return res;
}
void	removeOuterWS(std::string& line)
{
	if (line[0] == ' ' && line[line.size() - 1] == ' ')
	{
		line = line.substr(1, line.size() - 1);
		removeOuterWS(line);
	}
	else if (line[0] == ' ')
	{
		line = line.substr(1, line.size());
		removeOuterWS(line);
	}
	else if (line[line.size() - 1] == ' ')
	{
		line = line.substr(0, line.size() - 1);
		removeOuterWS(line);
	}
}

float verifyVal(std::string val)
{
	if (!(is_digits(val)) || count(val, '.') > 1 || val[0] == '.')
		throw BadInputException(val);
	float res;

	res = atof(val.c_str());
	if (res < 0)
		throw (std::runtime_error("not a positive number"));
	else if (res > 1000)
		throw (std::runtime_error("too large a number"));
	return (res);
}

void	verifyDate(std::string key)
{
	size_t i1 = key.find('-');
	size_t i2 = key.find('-', i1);
	size_t i3 = key.find_first_not_of("0123456789-");
	
	if (i3 != std::string::npos)
		throw BadInputException(key);
	std::string year = key.substr(0, i1);
	std::string month = key.substr(i1 + 1, i2 - 2);
	std::string day = key.substr(i2 + 4, i3 - 1);

	if ((atoi(year.c_str()) < 0 || year.size() > 4) || (atoi(day.c_str()) > 31) || (atoi(month.c_str()) > 12))
		throw BadInputException(key);
}

void	parseLine(std::string line, std::map<std::string,float> &data_map)
{
	try
	{
		if (line.find('|') == std::string::npos)
			throw BadInputException(line);
		std::string key = line.substr(0, line.find('|'));
		removeOuterWS(key);
		verifyDate(key);
		std::string strval = line.substr(line.find('|') + 1, line.size());
		removeOuterWS(strval);
		if (!strval.size())
			throw BadInputException(line);
		float val = verifyVal(strval);
		std::map<std::string, float>::iterator iter = data_map.find(key);
		if (iter == data_map.end())
		{
			iter = data_map.lower_bound(key);
			iter--;
		}
		std::cout << key << " => " << val << " = " << iter->second * val << std::endl;
	}
	catch(const BadInputException& e)
	{
		std::cout << "Error: " << e.what() << e.getLine() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
}

void	btc(std::ifstream &ifs, std::map<std::string,float> &data_map)
{
	std::string line;
	size_t 		lineIndex = 0;
	
	if (!std::getline(ifs, line))
		throw std::runtime_error("file is empty");
	while (1)
	{
		if (!std::getline(ifs, line))
			break;
		lineIndex++;
		parseLine(line, data_map);
	}
}

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
		std::map<std::string,float> data_map;
		buildMap(dfs, data_map);
		btc(ifs, data_map);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}