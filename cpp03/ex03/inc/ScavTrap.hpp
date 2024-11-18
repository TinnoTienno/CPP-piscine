/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 12:45:10 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap // virtual here is a solution for the diamond problem, only one instance of ClapTrap is called, then reinitialized
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