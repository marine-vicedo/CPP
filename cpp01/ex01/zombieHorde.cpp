/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:29:34 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 16:07:25 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
	Zombie *horde = new Zombie[N];
		
	for (int i = 0; i < N; i++)
	{
		std::string zombieName = name;
		horde[i].setName(zombieName);
	}
		
	return horde;
}

