/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:57:58 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	std::string _secret;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phonenumber;
public:
	Contact(std::string, std::string, std::string, std::string, std::string, void *, int);
	int			index;
	void	print_cont();
	void	display_info();
	Contact *next;
};

#endif
