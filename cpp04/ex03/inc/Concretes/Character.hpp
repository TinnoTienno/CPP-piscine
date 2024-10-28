/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:54:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 19:42:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"

class   Character : 
{
    private :
        AMateria    *Inventory[4];
        std::string name;
    public :
        Character();
        Character(const Character&);
        Character& operator=(const Character&);
        ~Character();
        
        Character& Clone();
        void equip(AMateria* m);
        void use(int idx, ICharacter& target);
        void equip(AMateria* m);
}   ;
#endif