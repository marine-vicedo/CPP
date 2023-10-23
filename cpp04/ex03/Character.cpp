/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:26:48 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:15:19 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/***************************/
/*Constructors & destrutors*/
/***************************/

Character:: Character()
{
	this->_name = "Unknown";
	std::cout << "A character "<< _name << " (default) is created" << std::endl;
	initInventory(this->_inventory);
	initUnequipTab(this->_leftMateria);
}

Character:: Character(std::string name)
{
	this->_name = name;
	std::cout << PURPLE "A character "<< _name << " has been created" NC << std::endl;
	initInventory(this->_inventory);
	initUnequipTab(this->_leftMateria);
}

Character:: Character(const Character &other)
{
	std::cout <<PURPLE "A copy of " << other._name << " character has been created" NC << std::endl;
	initInventory(this->_inventory);
	initUnequipTab(this->_leftMateria);
	*this = other;
}

Character &Character:: operator=(const Character &other)
{
	std::cout << PURPLE "Character assignement operator has been called" NC << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		deleteInventory(this->_inventory);
		deleteUnequipTab(this->_leftMateria);
		//deep copy
		for (int i = 0; i < 4; i++)
		{
			if(other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			if(other._leftMateria[i] != NULL)
				_leftMateria[i] = other._leftMateria[i]->clone();
		}
	}
	return (*this);
}

Character:: ~Character()
{
	std::cout << PURPLE "Character " << _name << " has been destroyed" NC << std::endl;
	deleteInventory(this->_inventory);
	deleteUnequipTab(this->_leftMateria);
}

/***************************/
/*		getter			   */
/***************************/

std::string const & Character:: getName() const
{
	return (this->_name);
}

/***************************/
/*		setter			   */
/***************************/

void	Character::setName(std::string const & newName)
{
	this->_name = newName;
	return ;
}

/***************************/
/*		methods			   */
/***************************/

void Character:: equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << _name << " can't equip with something that doesn't exist!" NC << std::endl;
		return ;
	}
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx] == NULL)
		{
			this->_inventory[idx] = m;
			std::cout << GREEN << _name << " equips " << m->getType() << " at slot " << idx << NC << std::endl;
			return ;
		}
	}
	std::cout << RED << _name << "can't equip more than 4 Materias" << NC << std::endl;
}

void Character:: unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
	{
		std::cout << RED << _name << " has nothing at this inventory slot " << idx << NC << std::endl;
		return ;
	} 
	std::cout << GREEN << _name << " unequips a materia of type " << this->_inventory[idx]->getType() << " at the index "
	<< idx << NC <<std::endl;
	this->_leftMateria[idx] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character:: use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
	{
		std::cout << _name << " has nothing in this inventory slot" << std::endl;
		return ;
	}
	std::cout << this->_name << " : ";
	this->_inventory[idx]->use(target);
	
}

/***************************/
/*	inventory init		   */
/***************************/

void Character:: initInventory(AMateria *inventory[4])
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

void Character:: deleteInventory(AMateria *inventory[4])
{
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

void	Character::displayInventory(void) const
{
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

void Character:: initUnequipTab(AMateria *leftMateria[4])
{
	for(int i = 0; i < 4; i++)
			leftMateria[i] = NULL;
}

void Character:: deleteUnequipTab(AMateria *leftMateria[4])
{
	for(int i = 0; i < 4; i++)
	{
		if (leftMateria[i] != NULL)
			delete leftMateria[i];
	}
}
