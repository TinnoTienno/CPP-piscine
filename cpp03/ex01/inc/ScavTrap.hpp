/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:29:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap // this is where the derived class is set up
{   //no attributes declaration
    public :
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ScavTrap operator=(const ScavTrap&);
        ~ScavTrap();
        
        void guardGate();
        void attack(const std::string&);
};

#endif