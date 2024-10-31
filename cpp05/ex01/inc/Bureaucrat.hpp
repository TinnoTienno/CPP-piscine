/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 18:59:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(const std::string&);
		Bureaucrat(const std::string&, const int&);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat&);

		std::ostream& operator<<(std::ostream& os);
		void setGrade(const int&);
		int	getGrade()	const;
		const std::string&	getName() const;
		void increment();
		void decrement();
		void signForm(Form &);
		
		class GradeTooHighException : public std::exception
		{
			int	_grade;
			virtual std::ostream& operator<<(std::ostream&);
			public : 
			GradeTooHighException();
			GradeTooHighException(const int&);
		}	GradeTooHighException;
		
		class GradeTooLowException : public std::exception
		{
			int	_grade;
			std::ostream& operator<<(std::ostream&);
			GradeTooLowException();
			GradeTooLowException(const int&);
		}	GradeTooLowException;
}	;
#endif