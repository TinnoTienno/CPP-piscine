/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:39:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 18:17:05 by eschussl         ###   ########.fr       */
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
        void    attack(const std::string);
    private :
        std::string name;
}   ;
#endif