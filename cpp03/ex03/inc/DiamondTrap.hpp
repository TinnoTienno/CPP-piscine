/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:39:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:47:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap : public FragTrap, public ScavTrap
{
    public : 
        DiamondTrap();
        DiamondTrap(std::string);
        DiamondTrap(const DiamondTrap&);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap&);
        
        void    whoAmI();
        using   ScavTrap::attack; //using here is allowed, helps specify which function to call when using attack()
    private :
        std::string m_name;
}   ;
#endif