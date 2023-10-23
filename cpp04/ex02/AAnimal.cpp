/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:34:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/16 14:22:10 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal:: AAnimal()
{
	std::cout << YELLOW "AAnimal default constructor is called" NC << std::endl;
	this->_type = "Unknown AAnimal";
	return ;
}

AAnimal:: AAnimal(std::string type)
{
	std::cout << ORANGE "AAnimal default constructor with type is called" NC << std::endl;
	this->_type = type;
	return ;
}

AAnimal:: AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor is called" << std::endl;
	*this = other;
	return ;
}

AAnimal &AAnimal:: operator=(const AAnimal &other)
{
	std::cout << "AAnimal assignement operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AAnimal:: ~AAnimal()
{
	std::cout << YELLOW "AAnimal default destructor is called" NC << std::endl;
	return ;
}

std::string const AAnimal:: getType() const
{
	return(this->_type);
}

void AAnimal:: makeSound() const
{
	std::cout << GREEN << this->_type << ": undefined sound" NC << std::endl;
	return ;
}