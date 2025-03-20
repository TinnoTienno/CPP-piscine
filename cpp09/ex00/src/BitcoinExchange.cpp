/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:20:52 by eschussl          #+#    #+#             */
/*   Updated: 2025/03/20 14:49:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>

static bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789.-") == std::string::npos;
}

static size_t	count(std::string val, char c)
{
	size_t res = 0;
	for (std::string::iterator it = val.begin(); it != val.end(); it++)
	{
		if (*it == c)
			res++;
	}
	return res;
}

static void	removeOuterWS(std::string& line)
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

static std::string findkey(std::string &line)
{
	return line.substr(0, line.find(","));
}

float findval(std::string &line)
{
	std::string res = line.substr(line.rfind(",") + 1, line.size() - 1);
	return (float) atof(res.c_str());
}

BadInputException::BadInputException(const std::string& Line) : m_line(Line) {  }

const std::string BadInputException::getLine() const { return (m_line); }

const char* BadInputException::what() const throw() { return "bad input => "; }

BadInputException::~BadInputException() throw() { };


BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::ifstream &dfs, std::ifstream &ifs) 
{
	buildMap(dfs);
	convert(ifs);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { *this = obj; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->_data_map = obj._data_map;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }


void BitcoinExchange::buildMap(std::ifstream &dfs)
{
	std::string line;
	std::getline(dfs, line); //takes out the first line defining format
	while (1)
	{
		if (!std::getline(dfs, line))
			break;
		_data_map.insert(std::make_pair(findkey(line), findval(line)));
	}
}

void	BitcoinExchange::convert(std::ifstream &ifs)
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
		parseLine(line);
	}
}

void	BitcoinExchange::verifyDate(std::string key)
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

float BitcoinExchange::verifyVal(std::string val)
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

void	BitcoinExchange::parseLine(std::string line)
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
		std::map<std::string, float>::iterator iter = _data_map.find(key);
		if (iter == _data_map.end())
		{
			iter = _data_map.lower_bound(key); // we get the previous val to compare as asked in the subject
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