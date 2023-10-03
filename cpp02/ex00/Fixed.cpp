/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:59:02 by mvicedo          ###   ########.fr       */
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
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

int	Fixed:: getRawBits (void) const
{
	std::cout << GREEN "getRawBits member function called" NC << std::endl;
	return (_value);
}

void	Fixed:: setRawBits (int const raw)
{
	_value = raw;
	return;
}
