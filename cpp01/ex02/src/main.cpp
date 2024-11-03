/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:40:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/03 15:22:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str; // very important to understand considering we'll keep using them since
	

	std::cout << "&str : " << &str << std::endl;
	std::cout << "stringPTR :" << stringPTR << std::endl;
	std::cout << "&stringREF :" << &stringREF << std::endl;
	
	std::cout << "str :" << str << std::endl;
	std::cout << "stringPTR :" << *stringPTR << std::endl; // need to dereference in the case of pointer whereas references dont need to
	std::cout << "stringREF :" << stringREF << std::endl;
}