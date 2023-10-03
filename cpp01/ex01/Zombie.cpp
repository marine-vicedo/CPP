/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:33:06 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 13:32:41 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie appeared!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " zombie died!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl << std::endl;
}

void	Zombie::setName(std::string const name)
{
	this->_name = name;
	return ;
}
