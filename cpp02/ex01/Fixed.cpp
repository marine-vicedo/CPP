/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 18:01:22 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << CYAN "Default constructor called" NC << std::endl;
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

Fixed::Fixed(const int value) : _value(value << _fractionnalBits)
{
	std::cout << CYAN "Int constructor called" NC << std::endl;
	return ;
}


Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionnalBits)))
{
	std::cout << CYAN "Float constructor called" NC << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << CYAN "Destructor called" NC << std::endl;
	return ;
}

int	Fixed:: getRawBits (void) const
{
	return (_value);
}

void	Fixed:: setRawBits (int const raw)
{
	_value = raw;
	return ;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionnalBits);
}

float Fixed::toFloat(void) const
{
	return((float)_value / (1 << _fractionnalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	os << number.toFloat();
	return (os);
}
