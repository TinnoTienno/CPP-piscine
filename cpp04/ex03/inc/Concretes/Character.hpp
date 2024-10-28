/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:54:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/28 21:09:53 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class   Character : public ICharacter
{
    private :
        AMateria    *Inventory[4];
        std::string name;
    public :
        Character();
        Character(const Character&);
        Character& operator=(const Character&);
        ~Character();
        
        std::string const & getName();
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
}   ;
#endif