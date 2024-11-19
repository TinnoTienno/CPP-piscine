/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:03:43 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 17:10:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <exception>
# include <string>

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

#endif