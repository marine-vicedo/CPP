/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:00:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/05 16:54:33 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << PURPLE "ScavTrap : Default constructor is called" NC << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << PURPLE "ScavTrap " << this->_name << ": Constructor is called" NC << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
	std::cout << PURPLE "ScavTrap : Copy constructor is called" NC<< std::endl;
	*this = other;
	return ;
}

ScavTrap &ScavTrap:: operator=(const ScavTrap &other)
{
	std::cout << PURPLE "ScavTrap : Copy assignement operator is called" NC << std::endl;
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

ScavTrap::~ScavTrap()
{
	std::cout << PURPLE "ScavTrap " << this->_name << ": Destructor is called" NC << std::endl;
	return ;
}

void ScavTrap:: attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack, it is dead" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack, it has no energy" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"<< std::endl;
	return ;
}

void ScavTrap:: guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode" << std::endl;
	return ;
}