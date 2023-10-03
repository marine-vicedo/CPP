/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:34:50 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 14:18:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->setType(weaponType);
	return;
}

Weapon::~Weapon()
{
	return ;
}

void Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}

std::string const &Weapon::getType(void)
{
	return (this->_type);
}
