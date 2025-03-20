/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:03:43 by eschussl          #+#    #+#             */
/*   Updated: 2025/03/20 14:24:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <exception>
# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include <stdlib.h>
# include <iomanip>

class BadInputException : public std::exception
{
	private :
		const std::string m_line;
	public :
		BadInputException(const std::string&);
		const std::string getLine() const;
		virtual const char* what() const throw();
		~BadInputException() throw();
}	;

class BitcoinExchange
{
	private :
		std::map<std::string,float> _data_map; // use of map container
	public :
		BitcoinExchange();
		BitcoinExchange(std::ifstream &dfs, std::ifstream &ifs);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();


		void		buildMap(std::ifstream &dfs);
		void		convert(std::ifstream &ifs);
		void		parseLine(std::string line);
		void		verifyDate(std::string key);
		float  		verifyVal(std::string val);
}	;
#endif