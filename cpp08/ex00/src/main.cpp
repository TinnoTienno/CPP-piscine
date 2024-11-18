/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:39:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 15:18:28 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> Vec(1);
	
	for (int i = 0; i < 10; i++)
		Vec.push_back(i + 2);
	std::cout << "return : " << *easyfind(Vec, 3) << std::endl;
}