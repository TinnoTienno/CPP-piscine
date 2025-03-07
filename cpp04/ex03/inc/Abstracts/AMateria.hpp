/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:25:57 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:30 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    
    public:
        AMateria *next;
    AMateria();
    AMateria(std::string const &);
    AMateria(const AMateria&);
    AMateria& operator=(const AMateria&);
    virtual ~AMateria();
    
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif