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
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scavtrap1("Simon");
	FragTrap fragtrap1("Rob");

	std::cout << YELLOW << "Rob Hit Points : " << fragtrap1.getHitPoints() << " - Energy Points : " 
	<< fragtrap1.getEnergyPoints() << " - Attack damage : " << fragtrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	scavtrap1.attack("Rob");
	fragtrap1.takeDamage(20);
	fragtrap1.beRepaired(10);
	fragtrap1.highFivesGuys();

	std::cout << YELLOW << "Rob Hit Points : " << fragtrap1.getHitPoints() << " - Energy Points : " 
	<< fragtrap1.getEnergyPoints() << " - Attack damage : " << fragtrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	fragtrap1.attack("Simon");
	scavtrap1.takeDamage(30);
	scavtrap1.beRepaired(7);
	scavtrap1.guardGate();

	std::cout << YELLOW << "Rob Hit Points : " << fragtrap1.getHitPoints() << " - Energy Points : " 
	<< fragtrap1.getEnergyPoints() << " - Attack damage : " << fragtrap1.getAttackDamage() << std::endl;
	std::cout << "Simon Hit Points : " << scavtrap1.getHitPoints() << " - Energy Points : " 
	<< scavtrap1.getEnergyPoints() << " - Attack damage : " << scavtrap1.getAttackDamage() << std::endl << NC;

	return (0);
}