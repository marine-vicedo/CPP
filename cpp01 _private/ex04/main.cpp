/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:00:42 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 15:17:25 by mvicedo          ###   ########.fr       */
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

	in_file.open(file.c_str(), std::ios::in); //c_str() is used to convert a C++ string to a C string (char *), needed for open()
	if (!in_file)
		std::cout << "Error opening file" << std::endl;
	out_file.open((file + ".replace").c_str(), std::ios::out);
	if (!out_file)
		std::cout << "Error opening file" << std::endl;
	else
	{
		while (std::getline(in_file, line)) // read an entire line (until \n) in in_file and save it in line.
		{
			pos = 0; // find first occurence of s1
			// while s1 is found. std:;string::npos means "until the end of the string". 
			//As a return value, it is usually used to indicate no matches.
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				new_line = line.substr(0, pos) + s2; // copy everything before s1 and add s2
				new_line += line.substr(pos + s1.length()); // copy everything after s1
				pos += s2.length(); // update pos to the end of s2
				line = new_line; // update line with new_line
			}
			out_file << line; // write line in out_file
			if (!in_file.eof()) // if we are not at the end of the file
				out_file << std::endl; // add a new line in out_file
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