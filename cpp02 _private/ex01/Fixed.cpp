/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:08:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:49:30 by mvicedo          ###   ########.fr       */
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
	std::cout << YELLOW "Copy assignment operator called" NC << std::endl;
	if (this != &other) //vérifie si l'objet actuel (pointé par this) est différent de l'objet source (other).
		_value = other.getRawBits();
	return (*this);
}

// Constructeur à partir d'un entier, convertit en virgule fixe
// Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(const int value) : _value(value << _fractionnalBits) //left bitshifting de 8
{
	std::cout << CYAN "Int constructor called" NC << std::endl;
	return ;
}

// Constructeur à partir d'un float, convertit en virgule fixe
//Le nombre de bits de la partie fractionnaire est initialisé à 8
//roundf pour faire un arrondi de la valeur obtenue
//1 << _fractionalBits -> 1 << 2^8 -> on decale de 8 positions
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

/************************/
/* FONCTIONS            */
/************************/

// Fonction membre pour obtenir la valeur brute sans conversion.
int	Fixed:: getRawBits (void) const
{
	//std::cout << GREEN "getRawBits member function called" NC << std::endl;
	return (_value);
}

// Fonction membre pour initialiser la valeur brute.
void	Fixed:: setRawBits (int const raw)
{
	//std::cout << GREEN "setRawBits member function called" NC << std::endl;
	_value = raw;
	return ;
}

//convertit la valeur en virgule fixe en nombre entier
int	Fixed::toInt(void) const
{
	return (_value >> _fractionnalBits);
}

//convertit la valeur en virgule fixe en nombre à virgule flottante
float Fixed::toFloat(void) const
{
	return((float)_value / (1 << _fractionnalBits));
}

//Les opérateurs de flux sont définis par défaut pour les types de variables int  , double  , char  ,
// ainsi que pour les objets comme string
// mais pas definis pour nos classes
// surcharge de l’opérateur d’insertion («) qui insère une représentation en virgule
// flottante du nombre à virgule fixe dans le flux de sortie
std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	os << number.toFloat();
	return (os);
}
