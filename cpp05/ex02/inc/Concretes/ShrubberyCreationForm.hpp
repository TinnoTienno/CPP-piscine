/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/02 18:07:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

//#define ASCII_TREE "              v .   ._, |_  .,\n           `-._\\/  .  \\ /    |/_\n               \\  _\\, y | \\//\n         _\\_.___\\, \\/ -.\\||\n           `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'\n                     |    |//\n                     |_    /\n                     |-   |\n                     |   =|\n                     |    |\n--------------------/ ,  . \\--------._"
#define ASCII_TREE "              v .   ._, |_  .,\n" \
                   "           `-._\\/  .  \\ /    |/_\n" \
                   "               \\  _\\, y | \\//\n" \
                   "         _\\_.___\\, \\/ -.\\||\n" \
                   "           `7-,--.`._||  / / ,\n" \
                   "           /'     `-. `./ / |/_.'\n" \
                   "                     |    |//\n" \
                   "                     |_    /\n" \
                   "                     |-   |\n" \
                   "                     |   =|\n" \
                   "                     |    |\n" \
                   "--------------------/ ,  . \\--------._" \

class ShrubberyCreationForm : public AForm
{
	private : 
		const std::string	_target;
	
	public :
		ShrubberyCreationForm(const std::string&);
		const std::string& getTarget() const;
		void execute(Bureaucrat const &obj) const;
} ;
#endif