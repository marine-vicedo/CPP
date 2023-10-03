/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:54:21 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 15:46:11 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie Zombie1 = Zombie("Anna");
	Zombie1.announce();

	Zombie *Zombie2 = newZombie("Hector");
	Zombie2->announce();

	randomChump("Eugene");
	delete Zombie2;

	Zombie	*Zombie3 = newZombie("Emma");
	Zombie3->announce();

	delete Zombie3;

	return (0);
}