/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:10:01 by noda              #+#    #+#             */
/*   Updated: 2025/01/28 18:05:25 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private :
		const std::string 	m_name;
		unsigned short 		m_grade;
		void	checkGrade();
	public :
		Bureaucrat();
		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, const short &grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		const std::string &getName() const;
		const unsigned short &getGrade() const;
		Bureaucrat &operator++(int);
		Bureaucrat &operator--(int);
		
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
}   ;

std::ostream& operator<<(std::ostream &out, Bureaucrat const& obj);
std::string itoa(int nb);
	

#endif