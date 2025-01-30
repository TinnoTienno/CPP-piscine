/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:24:53 by eschussl          #+#    #+#             */
/*   Updated: 2025/01/30 14:35:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	private :
		const std::string	m_name;
		bool				m_isSigned;
		const int			m_gradeToSign;
		const int			m_gradeToExec;
		void				checkGrade();
	public :
		Form();
		Form(const Form&);
		Form(const std::string&, const int&, const int&);
		Form& operator=(const Form&);
		~Form();

		const std::string& getName() const;
		const int& 	getGradeToSign() const;
		const int& 	getGradeToExec() const;
		const bool& getBool() const;
		
		void beSigned(const Bureaucrat&);
		
		class GradeTooHighException : public std::exception // Derived from exception so to be read from main with catch(std::exception&)
		{
			const std::string		m_message;
			public :
				GradeTooHighException(const std::string &name, const int &grade);
				~GradeTooHighException() throw();
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
		
		class GradeTooLowException : public std::exception
		{
			const std::string	m_message;

			public :
				GradeTooLowException(const std::string &name, const int &grade);
				GradeTooLowException(const std::string &name, const int &grade, const std::string &bureaucratName, const int &bureaucratGrade);
				~GradeTooLowException() throw();
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
}	;

std::ostream& operator<<(std::ostream&, Form const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)

#endif