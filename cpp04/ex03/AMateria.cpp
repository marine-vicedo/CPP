/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:22:19 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 11:16:59 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria:: AMateria()
{
	std::cout << "AMateria by default has been created" << std::endl;
}

AMateria:: AMateria(std:: string const & type)
{
	std::cout << BLUE "AMateria with type has been created" NC << std::endl;
	this->_type = type;
}

AMateria:: AMateria(const AMateria &other)
{
	std::cout << BLUE "AMateria has been created by copy" NC << std::endl;
	this->_type = other._type;
}

AMateria &AMateria:: operator=(const AMateria &other)
{
	std::cout << BLUE "AMateria copy assignement operator is called" NC << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria:: ~AMateria()
{
	std::cout << BLUE "AMateria destructor is called" NC << std::endl;
}

std::string const &AMateria:: getType() const
{
	return (this->_type);
}

void AMateria:: use(ICharacter &target)
{
	std::cout << BLUE "AMateria is used against " NC << target.getName() << std::endl;
}

