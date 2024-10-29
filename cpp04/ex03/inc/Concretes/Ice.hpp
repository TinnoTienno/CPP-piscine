/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/29 12:55:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
    public :
        Ice();
        Ice(const Ice&);
        Ice& operator=(const Ice&);
        ~Ice();
        
        void    use(ICharacter&);
        AMateria*    clone() const;
}   ;

#endif