/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 14:02:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private : 
		const std::string	m_target;
	
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();

		const std::string& getTarget() const;
		void execute(Bureaucrat const &obj) const;
} ;
#endif