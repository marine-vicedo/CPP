/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:13:43 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 10:42:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define dBfile "./data.csv"

bool isEmptyLine(std::string &line)
{
	if (line.empty())
		return (true);
	for (unsigned int i = 0; i < line.length(); i++)
	{
		if (isspace(line[i]) == 0)
			return (false);
	}
	return (true);
}

std::string strtrim(std::string src)
{
	size_t start = src.find_first_not_of(" \t");
	if (start == std::string::npos)
		throw std::runtime_error("Error: missing date or value");

	size_t end = src.find_last_not_of(" \t");
	return src.substr(start, end - start + 1);
}

void checkInput(char *filePath)
{
	struct stat fileInfo;
	if (stat(filePath, &fileInfo) != 0)
		throw (std::runtime_error ("Invalid file"));
	if (S_ISDIR(fileInfo.st_mode) != 0)
		throw (std::runtime_error ("File is a directory"));
	if ((fileInfo.st_mode & S_IXUSR) != 0)
		throw (std::runtime_error ("File is an executable"));
	return;
}

int main(int ac, char **av)
{
	BitcoinExchange btc;
	
	try
	{
		if (ac != 2)
			throw (std::runtime_error ("Usage : ./btc <input.txt>"));
		checkInput(av[1]);
		std::ifstream dataB(dBfile);
		if (!dataB.is_open())
			throw (std::runtime_error ("Error : could not open database file"));
		btc.readDataBase(dataB);
		btc.readInputFile(av[1]);
		dataB.close();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}