/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:57:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/19 12:58:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	MutantStack<std::string> m2stack;
	m2stack.push("yo");
	m2stack.push("ca");
	m2stack.push("va");

	std::cout << m2stack.top() << std::endl;
	
	MutantStack<int>::iterator it;
	// (void) it;
}