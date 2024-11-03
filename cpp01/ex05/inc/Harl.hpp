/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:43:40 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 16:21:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	private :
		void	debug();
		void	info();
		void	warning();
		void	error();
		void	(Harl::*function[4])();
	public:
		void	complain(std::string );
		Harl();
};
#endif