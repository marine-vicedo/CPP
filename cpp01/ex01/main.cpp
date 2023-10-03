/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:55:18 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 16:02:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int getNbZombies(void)
{
	int nb;
	std::cout << RED << "How many zombies do you want to create? " << NC << std::endl << " > ";
	while (!(std::cin >> nb) || nb > LIMIT_MAX || nb < 1)
	{
		if (std::cin.eof())
			return (0);
		std::cout << RED << "Choose a number between 1 and " << LIMIT_MAX << NC << std::endl << " > ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (nb);
}

std::string getHordeName(void)
{
	std::string hordeName;

	std::cin.ignore();
	std::cout << RED << "What name do you want to give to the horde? " << NC << std::endl << " > ";
	std::getline(std::cin, hordeName);
	if (std::cin.eof())
	{
		return (std::string());
	}
	return (hordeName);
}

int main(void)
{
	int nbZ;
	std::string hordeName;

	nbZ = getNbZombies();
	hordeName = getHordeName();
	
	std::cout << GREEN << "OK let's create the horde \'" << hordeName << "\' of " << nbZ << " zombies..." << NC << std::endl;
	std::cout << GREEN << "Allocating space for zombies..." << NC << std::endl;
	Zombie *horde = zombieHorde(nbZ, hordeName);
	if (horde == NULL)
	{
		std::cout << "The Horde failed to be create." << std::endl;
		return (1);
	}
	std::cout << RED << "Mwahaha we have our " << nbZ << " zombies...!" << NC << std::endl << std::endl;
	for ( int i = 0; i < nbZ; i++ )
		horde[i].announce();
	delete [] horde;
	std::cout << GREEN << "Well done ! You've killed them all." << NC << std::endl << std::endl;
	return (0);
}