/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:23:21 by noda              #+#    #+#             */
/*   Updated: 2025/01/29 16:36:07 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#define FIRST_TREE "Oak.tree"
#define SECOND_TREE "Pine.tree"
#define THIRD_TREE "Dead.tree"

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string m_target;
	public :
		ShrubberyCreationForm(const std::string &target);
		void		execute(Bureaucrat const &executor) const;

}	;
#endif 