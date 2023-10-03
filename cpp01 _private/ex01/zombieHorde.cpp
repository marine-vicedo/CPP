/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:29:34 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 14:00:54 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
	Zombie *horde = new Zombie[N]; // Allouer N objets Zombie en une seule allocation
		
	for (int i = 0; i < N; i++)
	{
		std::string zombieName = name;
		horde[i].setName(zombieName); // Utiliser le constructeur surchargé pour initialiser les zombies
	}
		
	return horde; // Retourner un pointeur sur le premier zombie
}

