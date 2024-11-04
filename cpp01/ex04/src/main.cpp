/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:03:26 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/04 16:23:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	err(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}
int	f_err(char *filename)
{
	std::ifstream ifs(filename);
	if (ifs.fail())
		return (1);
	std::string outfile = filename;
	outfile += ".replace";
	std::ofstream ofs(outfile.c_str());
	if (ofs.fail())
		return (1);
	return (0);
}
std::string get_file(char *filename)
{
	std::ifstream ifs(filename);
	std::string res;
	std::string tmp;
	while(std::getline (ifs, tmp))
	{
		res += tmp;
		res += '\n';
	}
	return (res);
}
void	replace(char *filename, std::string in, std::string out)
{
	std::string outfile = filename;
	outfile += ".replace";
	std::ofstream ofs(outfile.c_str()); // no need to open or close, the constructor and destructor of std::ofstream will do it for you
	std::string filestring = get_file(filename);
	size_t pos = 0;
	if (!in.size())
	{
		std::cout << "No key was given." << std::endl;
		return ;
	}
	while (filestring.find(in, pos) != std::string::npos)
	{
		pos = filestring.find(in, pos);
		filestring.erase(pos, in.size());
		filestring.insert(pos, out);
		pos++;
	}
	ofs << filestring;
}

int	main(int argc, char **argv) // arg1 = filename, arg2 key, arg3 replacement
{
	if (argc != 4)
		return (err("Args error"));
	if (f_err(argv[1]))
		return (err("File error"));
	replace(argv[1], argv[2], argv[3]);
}