/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:51:13 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:11:22 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal:: WrongAnimal()
{
	std::cout << YELLOW "WrongAnimal default constructor is called" NC << std::endl;
	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal:: WrongAnimal(std::string type)
{
	std::cout << ORANGE "WrongAnimal default constructor with type is called" NC << std::endl;
	this->_type = type;
	return ;
}

WrongAnimal:: WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
	*this = other;
	return ;
}

WrongAnimal &WrongAnimal:: operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignement operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongAnimal:: ~WrongAnimal()
{
	std::cout << YELLOW "WrongAnimal default destructor is called" NC << std::endl;
	return ;
}

std::string const WrongAnimal:: getType() const
{
	return(this->_type);
}

void WrongAnimal:: makeSound() const
{
	std::cout << GREEN << this->_type << ": undefined sound" NC << std::endl;
	return ;
}