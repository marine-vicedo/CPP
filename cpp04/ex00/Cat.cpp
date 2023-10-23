/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:59:41 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 13:58:05 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat:: Cat() : Animal("Cat")
{
	std::cout << CYAN "Cat default constructor is called" NC << std::endl;
	return ;
}

Cat:: Cat(const Cat &other)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = other;
	return ;
}

Cat &Cat:: operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cat:: ~Cat()
{
	std::cout << CYAN "Cat default destructor is called" NC << std::endl;
	return ;
}

void Cat:: makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaouuuu" NC << std::endl;
	return ;
}