/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:24:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 13:56:09 by eschussl         ###   ########.fr       */
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
			const int		m_grade;
			public :
				GradeTooHighException();
				GradeTooHighException(const int&);
				const int& getGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
		
		class GradeTooLowException : public std::exception
		{
			const int		m_burGrade;
			const int		m_formGrade;

			public :
				GradeTooLowException();
				GradeTooLowException(const int&);
				GradeTooLowException(const int&, const int&);
				const int& getBurGrade() const;
				const int& getFormGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
}	;

std::ostream& operator<<(std::ostream&, Form const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)

#endif