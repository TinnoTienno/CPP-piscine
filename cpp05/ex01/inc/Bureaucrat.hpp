/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/01 13:23:22 by eschussl         ###   ########.fr       */
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
		
		void	increment();
		void	decrement();

		void signForm(Form&) const;
		
		class GradeTooHighException : public std::exception // Derived from exception so to be read from main with catch(std::exception&)
		{
			virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	GradeTooHighException;
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	GradeTooLowException;
}	;

std::ostream& operator<<(std::ostream&, Bureaucrat const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)
#endif