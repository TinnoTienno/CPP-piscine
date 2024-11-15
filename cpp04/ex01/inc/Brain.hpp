/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:42:51 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 12:34:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain& operator= (const Brain&);
		
		void setIdea(const int, const std::string);
		std::string getIdea(const int) const;
}	;
#endif