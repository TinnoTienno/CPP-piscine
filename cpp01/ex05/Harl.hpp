/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:43:40 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 16:13:19 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	public:
		void	complain( std::string level);
};
#endif