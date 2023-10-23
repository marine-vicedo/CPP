/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:47:24 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:07:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog:: WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << PURPLE "WrongDog default constructor is called" NC << std::endl;
	return ;
}

WrongDog:: WrongDog(const WrongDog &other)
{
	std::cout << "WrongDog copy constructor is called" << std::endl;
	*this = other;
	return ;
}

WrongDog &WrongDog:: operator=(const WrongDog &other)
{
	std::cout << "WrongDog assignement operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongDog:: ~WrongDog()
{
	std::cout << PURPLE "WrongDog default destructor is called" NC << std::endl;
	return ;
}


void WrongDog:: makeSound() const
{
	std::cout << PURPLE << this->_type << ": WoufWouf" NC << std::endl;
	return ;
}