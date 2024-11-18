/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Purge.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:04:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PURGE_HPP
#define PURGE_HPP
#include "AMateria.hpp"

class Purge : public AMateria
{
	public :
        Purge();
        Purge(const Purge&);
        Purge& operator=(const Purge&);
        ~Purge();
        
        void    use(ICharacter&);
        AMateria*    clone() const;
}	;

#endif