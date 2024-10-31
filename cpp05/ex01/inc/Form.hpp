/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:05 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 19:03:15 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		Form();
		Form(const Form&);
		Form(const std::string&, const int&, const int&);
		Form& operator=(const Form&);
		~Form();

		std::string getName() const;
		int			getSigning() const;
		int			getExec()	const;
		bool		getBool()	const;
		void		setSign(const bool&);
		void 		beSigned(const Bureaucrat&);
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		}	GradeTooLowException;
		
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		}	GradeTooHighException;
		
	private :
		const std::string	_name;
		bool				_sign;
		const int			_signingGrade;
		const int			_executingGrade;
}	;
#endif