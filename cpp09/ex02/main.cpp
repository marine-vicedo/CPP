/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:37:44 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 11:21:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void inputCheck(int ac, char **av)
{
	std::string allowed = "0123456789 ";
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];
		size_t found = input.find_first_not_of(allowed);
		if (found != std::string::npos)
			throw std::invalid_argument("Invalid input : only positive numbers allowed");
	}
	
	std::vector<unsigned int> input;
	for (int i = 1; i < ac; i++)
	{
		std::string numStr = av[i];
		if (numStr.length() > 10)
			throw std::out_of_range("Invalid input : int max");
		unsigned int num = strtoul(av[i], NULL, 10);
		if (num > 2147483647)
			throw std::invalid_argument("Invalid input : int max");
		input.push_back(num);
	}

	std::vector<unsigned int>::iterator it1;
	std::vector<unsigned int>::iterator it2;
	for (it1 = input.begin(); it1 != input.end(); it1++)
	{
		for (it2 = it1 + 1; it2 != input.end(); it2++)
			if (*it2 == *it1)
				throw std::invalid_argument("Invalid input : no duplicates allowed");
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <number1> <number2> ..." << std::endl;
		return (1);
	}

	try
	{
		inputCheck(ac, av);
		PmergeMe pmm;
		pmm.sortVector(ac, av);
		pmm.sortList(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}