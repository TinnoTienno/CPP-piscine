/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 12:55:48 by eschussl         ###   ########.fr       */
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
	
		const std::string	_name;
		int					_grade;
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
			private:
			const int		_grade;
			public :
				GradeTooHighException();
				GradeTooHighException(const int&);
				const int& getGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
		class GradeTooLowException : public std::exception
		{
			const int		_grade;
			public :
				GradeTooLowException();
				GradeTooLowException(const int&);
				const int& getGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		};
};

std::ostream& operator<<(std::ostream&, Bureaucrat const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)

#endif