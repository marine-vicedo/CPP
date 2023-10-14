/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:58:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 12:10:41 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("Anna");
	ScavTrap scavtrap1("Simon");

	std::cout << YELLOW << "Anna Hit Points : " << claptrap1.getHitPoints() << " - Energy Points : " 
	<< claptrap1.getEnergyPoints() << " - Attack damage : " << claptrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	claptrap1.attack("Simon");
	scavtrap1.takeDamage(20);
	scavtrap1.beRepaired(7);
	scavtrap1.guardGate();

	std::cout << YELLOW << "Anna Hit Points : " << claptrap1.getHitPoints() << " - Energy Points : " 
	<< claptrap1.getEnergyPoints() << " - Attack damage : " << claptrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	scavtrap1.attack("Anna");
	claptrap1.takeDamage(20);
	claptrap1.beRepaired(3);

	std::cout << YELLOW << "Anna Hit Points : " << claptrap1.getHitPoints() << " - Energy Points : " 
	<< claptrap1.getEnergyPoints() << " - Attack damage : " << claptrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	return (0);
}