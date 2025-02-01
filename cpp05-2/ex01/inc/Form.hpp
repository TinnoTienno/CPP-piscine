/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:18:17 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 18:42:01 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
	private :
		const std::string	m_name;
		bool				m_isSigned;
		const short			m_signingGrade;
		const short			m_execGrade;
		
		void		checkGrade();
	public :
		Form();
		Form(const std::string &name);
		Form(const std::string &name, const unsigned short &signingGrade, const unsigned short &execGrade);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();
		
		std::string	getName() const;
		bool		getBool() const;
		short		getSigningGrade() const;
		short		getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception
		{
			private :
				std::string 	m_message;
			public :
				GradeTooHighException(const unsigned short &grade);
				const char* what() const throw();
				~GradeTooHighException() throw();
		}	;
		class GradeTooLowException : public std::exception
		{
			private :
				std::string 	m_message;
			public :
				GradeTooLowException(const unsigned short &grade);
				const char* what() const throw();
				~GradeTooLowException() throw();
		}	;
}	;

std::ostream& operator<<(std::ostream &out, Form const& obj);

#endif