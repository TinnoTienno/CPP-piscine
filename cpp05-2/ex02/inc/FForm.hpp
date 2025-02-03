/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:59:51 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 15:41:35 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FFORM_HPP
#define FFORM_HPP
#include <string>
#include <iostream>


typedef enum e_type {
	defaultType,
	shrubberyCreationForm,
	robotomyRequestForm,
	presidentialPardonForm
	} e_type;


class AForm;
class FForm
{
	private :
		e_type getEnum(const std::string &type);
	public :
		AForm *make(const std::string &type, const std::string &target);
}	;
#endif