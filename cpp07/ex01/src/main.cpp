/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:51:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 18:08:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	print(std::string &str)
{
	std::cout << str << std::endl;
}
void	toupper(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}
int main()
{
	std::string tab[5] = {"Coucou", "Tu", "Vas", "Bien", "?"};

	::iter(tab, 5, print);
	::iter(tab, 5, toupper);
	::iter(tab, 5, print);
}

