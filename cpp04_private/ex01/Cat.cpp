/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:59:41 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 14:16:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat:: Cat() : Animal("Cat")
{
	std::cout << CYAN "Cat default constructor is called" NC << std::endl;
	this->_brain = new Brain();
	return ;
}

Cat:: Cat(const Cat &other)
{
	std::cout << CYAN "Cat copy constructor is called" NC << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other.getBrain());
	return ;
}

Cat &Cat:: operator=(const Cat &other)
{
	std::cout << CYAN "Cat copy assignment operator is called" NC << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
	}
	return (*this);
}

Cat:: ~Cat()
{
	delete this->_brain;
	std::cout << CYAN "Cat default destructor is called" NC << std::endl;
	return ;
}

void Cat:: makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaouuuu" NC << std::endl;
	return ;
}

Brain *Cat :: getBrain() const
{
	return (this->_brain);
}