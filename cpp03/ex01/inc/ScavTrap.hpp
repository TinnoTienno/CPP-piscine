/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/24 17:09:56 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ~ScavTrap();
        ScavTrap operator= (const ScavTrap&);
        void guardGate();
};

#endif