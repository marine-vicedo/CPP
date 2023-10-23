/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:19 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 13:57:59 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog:: Dog() : Animal("Dog")
{
	std::cout << PURPLE "Dog default constructor is called" NC << std::endl;
	return ;
}

Dog:: Dog(const Dog &other) : Animal(other._type)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = other;
	return ;
}

Dog &Dog:: operator=(const Dog &other)
{
	std::cout << "Dog assignement operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Dog:: ~Dog()
{
	std::cout << PURPLE "Dog default destructor is called" NC << std::endl;
	return ;
}

void Dog:: makeSound() const
{
	std::cout << PURPLE << this->_type << ": WoufWouf" NC << std::endl;
	return ;
}