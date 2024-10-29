/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/29 14:10:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
        Cure();
        Cure(const Cure&);
        Cure& operator=(const Cure&);
        ~Cure();
        
        void    use(ICharacter&);
        AMateria*    clone() const;
}	;

#endif