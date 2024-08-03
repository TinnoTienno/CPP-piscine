/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:09:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/26 13:37:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie *The_Horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		The_Horde[i].set(name);
		i++;
	}
	return (The_Horde);
}