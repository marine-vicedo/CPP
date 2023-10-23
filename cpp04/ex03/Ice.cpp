/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:48:03 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/19 13:34:10 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice:: Ice() : AMateria("ice")
{
	this->_type = "ice";
	std::cout << CYAN "Ice constructor is called" NC << std::endl;
}

Ice:: Ice(const Ice &other) : AMateria("ice")
{
	std::cout << CYAN "Ice copy constructor is called" NC << std::endl;
	*this = other;
}

Ice &Ice:: operator=(const Ice &other)
{
	std::cout << CYAN "Ice assignement operator is called" NC << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice:: ~Ice()
{
	std::cout << CYAN "Ice destructor is called" NC << std::endl;
}

AMateria *Ice:: clone() const
{
	AMateria *iceClone = new Ice();
	return (iceClone);
}

void Ice:: use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}