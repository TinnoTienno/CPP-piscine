/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 13:32:37 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private : 
		const std::string	m_name;
		int					m_grade;
		void				checkGrade() const;

	public :
		Bureaucrat();
		Bureaucrat(const std::string&, const int&);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();

		const std::string& getName()const ;
		const int& getGrade()const ;
		void	setGrade(const int &);

		Bureaucrat &operator++();
		Bureaucrat &operator--();
		void	signForm(Form &);

	class GradeTooHighException : public std::exception // Derived from exception so to be read from main with catch(std::exception&)
			{
				private :
					std::string		m_message;
				public :
					GradeTooHighException(const std::string &name, const int&);
					~GradeTooHighException() throw();
					virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
			}	;
			class GradeTooLowException : public std::exception
			{
				private :
					std::string		m_message;
				public :
					GradeTooLowException(const std::string &name, const int&);
					~GradeTooLowException() throw();
					virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
			}	;
};

std::ostream& operator<<(std::ostream&, Bureaucrat const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
std::string itoa(int nb);

#endif