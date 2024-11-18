/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 14:02:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private : 
		const std::string	m_target;
	
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		
		const std::string& getTarget() const;
		void execute(Bureaucrat const &obj) const;
} ;
#endif