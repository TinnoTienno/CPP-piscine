/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:40:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/26 15:09:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	

	std::cout << "&str : " << &str << std::endl;
	std::cout << "&stringPTR :" << &stringPTR << std::endl;
	std::cout << "&stringREF :" << &stringREF << std::endl;
	
	std::cout << "str :" << str << std::endl;
	std::cout << "stringPTR :" << stringPTR << std::endl;
	std::cout << "stringREF :" << stringREF << std::endl;
	
}