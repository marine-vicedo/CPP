/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:34:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/14 11:11:46 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal:: Animal()
{
	std::cout << YELLOW "Animal default constructor is called" NC << std::endl;
	this->_type = "Unknown Animal";
	return ;
}

Animal:: Animal(std::string type)
{
	std::cout << ORANGE "Animal default constructor with type is called" NC << std::endl;
	this->_type = type;
	return ;
}

Animal:: Animal(const Animal &other)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = other;
	return ;
}

Animal &Animal:: operator=(const Animal &other)
{
	std::cout << "Animal assignement operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Animal:: ~Animal()
{
	std::cout << YELLOW "Animal default destructor is called" NC << std::endl;
	return ;
}

std::string const Animal:: getType() const
{
	return(this->_type);
}

void Animal:: makeSound() const
{
	std::cout << GREEN << this->_type << ": undefined sound" NC << std::endl;
	return ;
}