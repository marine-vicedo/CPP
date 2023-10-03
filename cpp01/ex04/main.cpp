/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:00:42 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 16:08:54 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define RED  "\033[1;91m"
#define GREEN  "\033[1;92m"
#define CYAN  "\033[1;96m"
#define NC  "\033[0;39m"

void ft_replace(std::string file, std::string s1, std::string s2)
{
	std::fstream in_file;
	std::fstream out_file;
	std::string line;
	std::string new_line;
	size_t pos;

	in_file.open(file.c_str(), std::ios::in); 
	if (!in_file)
		std::cout << "Error opening file" << std::endl;
	out_file.open((file + ".replace").c_str(), std::ios::out);
	if (!out_file)
		std::cout << "Error opening file" << std::endl;
	else
	{
		while (std::getline(in_file, line))
		{
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				new_line = line.substr(0, pos) + s2;
				new_line += line.substr(pos + s1.length());
				pos += s2.length();
				line = new_line;
			}
			out_file << line;
			if (!in_file.eof())
				out_file << std::endl;
		}
	}
	in_file.close();
	out_file.close();
}

int main (int ac, char **av)
{
	if (ac == 4) 
	{
		if (!av[2][0] || !av[3][0])
			std::cout << "Strings can't be empty" << std::endl;
		else
		{
			std::cout << "Replacing " << GREEN << av[2] 
						<< NC << " by " << CYAN << av[3]
						<< NC << " in " << RED << av[1]
						<< NC << std::endl;
			ft_replace(av[1], av[2], av[3]);
		}
	}
	else 
		std::cout << "Wrong amount of arguments" << std::endl;
	return 0;
}