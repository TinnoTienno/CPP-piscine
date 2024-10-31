/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/31 16:56:10 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>

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
		std::string	getName() const;
		void increment();
		void decrement();
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		}	GradeTooHighException;
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		}	GradeTooLowException;
}	;
#endif