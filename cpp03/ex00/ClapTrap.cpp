/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:07:31 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/11 14:53:38 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN "ClapTrap : Default constructor is called" NC << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN "ClapTrap " << _name << ": Constructor is called" NC << std::endl;
	return ;
}


ClapTrap::ClapTrap (const ClapTrap &other) : _name(other._name)
{
	std::cout << CYAN "ClapTrap " << _name << ": Copy constructor is called" NC << std::endl;
	*this = other;
	return ;
}

ClapTrap &ClapTrap:: operator=(const ClapTrap &other)
{
	std::cout << CYAN "ClapTrap " << _name << ": Copy assignement operator is called" NC << std::endl;
	if(this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN "ClapTrap " <<_name << ": Destructor is called" NC << std::endl;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't attack, it is dead" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " can't attack, it has no energy" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"<< std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't take anymore damage : it is already dead" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " can't be repaired : it is already dead" << std::endl;
		return;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " can't be repaired, it has no energy" << std::endl;
		return;
	}
	if (this->_hitPoints + (int)amount > 10)
		amount = 10 - this->_hitPoints;
	std::cout << _name << " repairs itself for " << (int)amount << " hit points!" << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
	return ;
}

std::string ClapTrap::getName(void) const
{
	return(this->_name);
}

int ClapTrap::getHitPoints(void) const
{
	return(this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return(this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return(this->_attackDamage);
}