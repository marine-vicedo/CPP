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

int main(void)
{
	ClapTrap claptrap1("Anna");
	ClapTrap claptrap2("Lucie");

	claptrap1.attack("Lucie");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	std::cout << YELLOW << "Anna Hit Points : " << claptrap1.getHitPoints() << " - Energy Points : " 
	<< claptrap1.getEnergyPoints() << " - Attack damage : " << claptrap1.getAttackDamage() << std::endl;
	std::cout << "Lucie Hit Points : " << claptrap2.getHitPoints() << " - Energy Points : " 
	<< claptrap2.getEnergyPoints() << " - Attack damage : " << claptrap2.getAttackDamage() << std::endl << NC;

		
	claptrap2.attack("Anna");
	claptrap1.takeDamage(5000);
	claptrap1.beRepaired(5000);
	claptrap1.takeDamage(1);
	std::cout << YELLOW << "Anna Hit Points : " << claptrap1.getHitPoints() << " - Energy Points : " 
	<< claptrap1.getEnergyPoints() << " - Attack damage : " << claptrap1.getAttackDamage() << std::endl;
	std::cout << "Lucie Hit Points : " << claptrap2.getHitPoints() << " - Energy Points : " 
	<< claptrap2.getEnergyPoints() << " - Attack damage : " << claptrap2.getAttackDamage() << std::endl << NC;
		
	return (0);
}