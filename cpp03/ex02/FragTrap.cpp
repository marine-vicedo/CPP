/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:55:20 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/05 16:48:08 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << BLUE "FragTrap : Default constructor is called" NC << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE "FragTrap " << this->_name << ": Constructor is called" NC << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	return ;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	std::cout << BLUE "FragTrap : Copy constructor is called" NC << std::endl;
	*this = other;
	return ;
}

FragTrap &FragTrap:: operator=(const FragTrap &other)
{
	std::cout << BLUE "FragTrap : Copy assignement operator is called" NC << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_maxHitPoints = other._maxHitPoints;
		
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << BLUE "FragTrap " << this->_name << ": Destructor is called" NC << std::endl;
	return ;
}

void FragTrap:: highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " rises his hand and highs five" << std::endl;
	return ;
}
