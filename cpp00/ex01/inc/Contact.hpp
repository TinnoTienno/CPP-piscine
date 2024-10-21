/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:29:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/21 16:06:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private :
		std::string 	_FirstName;
		std::string 	_Secret;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
	public :
		Contact();
		~Contact();
		void AddData(std::string, std::string, std::string, std::string, std::string);
		void Display();
		void DisplayTab();
}	;
#endif