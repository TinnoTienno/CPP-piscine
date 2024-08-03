/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:08:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:10 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	Contact	*_head;
	int		_size;	
public:
	PhoneBook();
	void	add_cont();
	void	display();
	~PhoneBook();
};

#endif