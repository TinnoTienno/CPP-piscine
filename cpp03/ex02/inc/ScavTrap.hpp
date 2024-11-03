/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 17:33:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
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