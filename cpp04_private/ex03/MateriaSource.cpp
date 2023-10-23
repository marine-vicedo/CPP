/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:06:20 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/19 14:15:25 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource:: MateriaSource()
{
	std::cout << YELLOW "MateriaSource has been created" NC << std::endl;
	initTemplates(this->_templates);
}

MateriaSource:: MateriaSource(const MateriaSource &other)
{
	std::cout << YELLOW "MateriaSource has been created from copy" NC << std::endl;
	initTemplates(this->_templates);
	*this = other;
}

MateriaSource &MateriaSource:: operator=(const MateriaSource &other)
{
	std::cout << YELLOW "MateriaSource assignement operator is called" NC << std::endl;
	if (this != &other)
	{
		deleteTemplates(this->_templates);
		for (int i = 0; i < 4; i++)
		{
			if(other._templates[i])
				this->_templates[i] = other._templates[i]->clone();
		}
		
	}
	return (*this);
}

MateriaSource:: ~MateriaSource()
{
	std::cout << YELLOW "MateriaSource has been destroyed" NC << std::endl;
	deleteTemplates(this->_templates);
	return ;
}

//permet d'ajouter des templates de matérias
void MateriaSource:: learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << RED "Try to learn a materia that doesn't exists" NC << std::endl;
		return ;
	}
	for (int idx = 0; idx < 4; idx++)
	{
		if(this->_templates[idx] == NULL)
		{
			this->_templates[idx] = m;
			std::cout << GREEN "Materia " << _templates[idx]->getType() << " has been learned" NC << std::endl;
			return ;
		}
	}
	std::cout << RED "Can't learn more than 4 materias" NC << std::endl;
}

//permet de créer des matérias en utilisant les templates appris précédemment.
AMateria* MateriaSource:: createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] != NULL && (this->_templates[i]->getType() == type))
		{
			std::cout << GREEN "A Materia of type " << type << " has been created" NC << std::endl;
			return ((this->_templates[i]->clone()));
		}
	}
	std::cout << RED << type << " materia doesn't exist" NC << std::endl;
	return (NULL);
}

void MateriaSource:: initTemplates(AMateria *templates[4])
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

void MateriaSource:: deleteTemplates(AMateria *templates[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i])
			delete templates[i];
	}
}

void	MateriaSource::displayTemplates(void)
{
	std::cout << "MateriaSource knows the following templates:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_templates[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_templates[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}
