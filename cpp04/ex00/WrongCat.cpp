/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:37:17 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:06:39 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat:: WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << CYAN "WrongCat default constructor is called" NC << std::endl;
	return ;
}

WrongCat:: WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
	*this = other;
	return ;
}

WrongCat &WrongCat:: operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator is called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongCat:: ~WrongCat()
{
	std::cout << CYAN "WrongCat default destructor is called" NC << std::endl;
	return ;
}


void WrongCat:: makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaouuuu" NC << std::endl;
	return ;
}