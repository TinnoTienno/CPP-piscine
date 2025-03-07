/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:24:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 16:47:26 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;
class AForm
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public :
		AForm();
		AForm(const AForm&);
		AForm(const std::string&, const int&, const int&);
		AForm& operator=(const AForm&);
		~AForm();
		
		const std::string& getName() const;
		const int& 	getGradeToSign() const;
		const int& 	getGradeToExec() const;
		const bool& getBool() const;
		const std::string& getTarget() const;
		
		void beSigned(const Bureaucrat&);
		virtual void execute(Bureaucrat const &) const = 0;
		
		class GradeTooHighException : public std::exception // Derived from exception so to be read from main with catch(std::exception&)
		{
			const int		_grade;
			public :
				GradeTooHighException();
				GradeTooHighException(const int&);
				const int& getGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
		
		class GradeTooLowException : public std::exception
		{
			const int		_burGrade;
			const int		_formGrade;

			public :
				GradeTooLowException();
				GradeTooLowException(const int&);
				GradeTooLowException(const int&, const int&);
				const int& getBurGrade() const;
				const int& getFormGrade() const;
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;

		class IsntSignedException : public std::exception
		{
			public :
				virtual const char* what() const throw(); // Throw meaning it wont throw any exception / to prevent handling more than one exception at a time
		}	;
}	;

std::ostream& operator<<(std::ostream&, AForm const&); // Has to be outside of class definition overwise would use the friend keyword (forbidden by subject)

#endif