/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:39 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
	return ;
}

Fixed::Fixed (const Fixed &other)
{
	this->_value = other.getRawBits();
	return ;
}

Fixed &Fixed:: operator = (const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value) : _value(value << _fractionnalBits)
{
	return ;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionnalBits)))
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return(_value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return(_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return(_value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return(_value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return(_value != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}