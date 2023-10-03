/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:48:23 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
	std::cout << CYAN "Default constructor called" NC << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << CYAN "Destructor called" NC << std::endl;
	return ;
}

Fixed::Fixed (const Fixed &other)
{
	std::cout << CYAN "Copy constructor called" NC << std::endl;
	this->_value = other.getRawBits();
	return ;
}

Fixed &Fixed:: operator = (const Fixed &other)
{
	std::cout << YELLOW "Copy assignment operator called" NC << std::endl;
	if (this != &other) //vérifie si l'objet actuel (pointé par this) est différent de l'objet source (other).
		_value = other.getRawBits();
	return (*this);
}

// Fonction membre pour obtenir la valeur brute sans conversion.
int	Fixed:: getRawBits (void) const
{
	std::cout << GREEN "getRawBits member function called" NC << std::endl;
	return (_value);
}

//Fonction membre pour initialiser la valeur brute.
void	Fixed:: setRawBits (int const raw)
{
	std::cout << GREEN "setRawBits member function called" NC << std::endl;
	_value = raw;
	return;
}
