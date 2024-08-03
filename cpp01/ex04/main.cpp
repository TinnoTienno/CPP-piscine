/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:56:58 by eschussl          #+#    #+#             */
/*   Updated: 2024/08/03 15:39:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{

	char c = 1;
	
	if (argc != 4)
		return (1);
	std::ifstream ifs(argv[1]);
	std::string str = argv[1];
	str += ".replace";
	if (!(ifs >> std:: noskipws >> c))
		return (1);
	std::ofstream ofs(str.c_str());
	if (c == argv[2][0])
	{
		int i = 1;
		std::string buff;
		buff += c;
		while (argv[2][i] && ifs >> std::noskipws >> c && c == argv[2][i])
		{
			buff += c;
			i++;
		}
		if (!argv[2][i])
			ofs << argv[3];
		else
			ofs << buff << c;
	}
	else
		ofs << c;
	while 	(ifs >> std::noskipws >> c)
	{
		if (c == argv[2][0])
		{
			int i = 1;
			std::string buff;
			buff += c;
			while (argv[2][i] && ifs >> std::noskipws >> c && c == argv[2][i])
			{
				buff += c;
				i++;
			}
			if (!argv[2][i])
				ofs << argv[3];
			else
				ofs << buff << c;
		}
		else
			ofs << c;
	}
}