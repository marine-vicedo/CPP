/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:19 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 14:53:49 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog:: Dog() : AAnimal("Dog")
{
	std::cout << BLUE "Dog default constructor is called" NC << std::endl;
	this->_brain = new Brain;
	return ;
}

Dog:: Dog(const Dog &other) : AAnimal(other._type)
{
	std::cout << BLUE "Dog copy constructor is called" NC << std::endl;
	*this = other;
	return ;
}

Dog &Dog:: operator=(const Dog &other)
{
	std::cout << BLUE "Dog assignement operator is called" NC << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Dog:: ~Dog()
{
	delete this->_brain;
	std::cout << BLUE "Dog default destructor is called" NC << std::endl;
	return ;
}

void Dog:: makeSound() const
{
	std::cout << BLUE << this->_type << ": WoufWouf" NC << std::endl;
	return ;
}