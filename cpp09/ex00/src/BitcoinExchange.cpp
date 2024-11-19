/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:20:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 17:11:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>

BadInputException::BadInputException(const std::string& Line) : m_line(Line) {  }

const std::string BadInputException::getLine() const { return (m_line); }

const char* BadInputException::what() const throw() { return "bad input => "; }

BadInputException::~BadInputException() throw() { };
