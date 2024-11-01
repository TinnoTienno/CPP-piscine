/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:15:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/01 14:21:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public :
		Form();
		Form(const std::string&, const int&, const int&);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		
		const std::string 	getName() const;
		int 			getGradeToSign() const;
		int 			getGradeToExec() const;
		bool			getBool() const;
		
		void	beSigned(const Bureaucrat&);
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	GradeTooHighException;
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	GradeTooLowException;
		in


}	;

#endif