/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:36:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/19 13:36:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure:: Cure() : AMateria("cure")
{
	this->_type = "cure";
	std::cout << CYAN "Cure constructor is called" NC << std::endl;
}

Cure:: Cure(const Cure &other) : AMateria("cure")
{
	std::cout << CYAN "Cure copy constructor is called" NC << std::endl;
	*this = other;
}

Cure &Cure:: operator=(const Cure &other)
{
	std::cout << CYAN "Cure assignement operator is called" NC << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cure:: ~Cure()
{
	std::cout << CYAN "Cure destructor is called" NC << std::endl;
}

AMateria *Cure:: clone() const
{
	AMateria *CureClone = new Cure();
	return (CureClone);
}

void Cure:: use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}