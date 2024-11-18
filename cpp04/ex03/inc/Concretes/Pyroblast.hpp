/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pyroblast.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:07:37 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYROBLAST_HPP
#define PYROBLAST_HPP
#include "AMateria.hpp"

class Pyroblast : public AMateria
{
    public :
        Pyroblast();
        Pyroblast(const Pyroblast&);
        Pyroblast& operator=(const Pyroblast&);
        ~Pyroblast();
        
        void    use(ICharacter&);
        AMateria*    clone() const;
}   ;

#endif