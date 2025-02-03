/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:18:17 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 15:43:51 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
	private :
		const std::string	m_name;
		bool				m_isSigned;
		const short			m_signingGrade;
		const short			m_execGrade;
		
		void		checkGrade();
	public :
		AForm();
		AForm(const std::string &name);
		AForm(const std::string &name, const unsigned short &signingGrade, const unsigned short &execGrade);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();
		
		std::string	getName() const;
		bool		getBool() const;
		short		getSigningGrade() const;
		short		getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0 ;
		void		checkExec(const Bureaucrat &bureaucrat) const;
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

std::ostream& operator<<(std::ostream &out, AForm const& obj);

#endif