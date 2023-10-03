/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:54:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/************************/
/* CONSTRUCTEURS & 
DESTRUCTEURS            */
/************************/

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
	std::cout << YELLOW "Copy assignment called" NC << std::endl;
	if (this != &other) //vérifie si l'objet actuel (pointé par this) est différent de l'objet source (other).
		_value = other.getRawBits();
	return (*this);
}

// Constructeur à partir d'un entier
Fixed::Fixed(const int value) : _value(value << _fractionnalBits) //left bitshifting de 8
{
	std::cout << CYAN "Int constructor called" NC << std::endl;
	return ;
}

// Constructeur à partir d'un float
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionnalBits)))
{
	//conversion d'un nombre flottant en virgule fixe avec arrondi
	std::cout << CYAN "Float constructor called" NC << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << CYAN "Destructor called" NC << std::endl;
	return ;
}

/**************************/
/* Comparaison OPERATEURS */
/**************************/

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

/****************************/
/* Arithmetiques OPERATEURS */
/****************************/

//conversion temporaire en virgule flottante car la classe Fixed représente les nombres sous forme de nombres à virgule fixe, où une partie de la valeur est
//réservée pour la partie fractionnaire. Lorsque vous effectuez une opération arithmétique, comme l'addition, vous devez prendre en compte ces parties fractionnaires.
//Une fois l'addition effectuée en tant que float, le résultat est converti de nouveau en un objet Fixed à virgule fixe en utilisant le constructeur qui prend un float en paramètre.
//Cela permet de garantir que le résultat est correctement formaté en virgule fixe avant d'être retourné.

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

/****************************/
/* Incrementation
& decrementation OPERATEURS */
/****************************/

Fixed	&Fixed::operator++(void)//pre-incr
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)//post-incr
{
	Fixed tmp(*this);//cree une copie de l'objet actuel
	++(*this);//effectue l'incrementation de l'objet actuel
	return (tmp);//retourne la copie avant l'incrementation
}

Fixed	&Fixed::operator--(void)//pre-decr
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)//post-decr
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

/************************/
/* FONCTIONS            */
/************************/

// Fonction membre pour obtenir la valeur brute sans conversion.
int	Fixed:: getRawBits (void) const
{
	return (_value);
}

// Fonction membre pour initialiser la valeur brute.
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