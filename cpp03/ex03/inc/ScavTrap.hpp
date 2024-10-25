/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/10/25 14:34:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ~ScavTrap();
        ScavTrap operator= (const ScavTrap&);
        
        void setHP(void);
		void setEP(void);
		void setAD(void);
        void guardGate();
        void attack(const std::string&);
};

#endif