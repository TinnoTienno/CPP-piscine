/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:28:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 15:02:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "AMateria.hpp"

class Fireball : public AMateria
{
    public :
        Fireball();
        Fireball(const Fireball&);
        Fireball& operator=(const Fireball&);
        ~Fireball();
        
        void    use(ICharacter&);
        AMateria*    clone() const;
}   ;

#endif