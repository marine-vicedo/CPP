/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:40:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:53:46 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // Pour la fonction roundf

#define NC "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

class Fixed
{
	private:
		int _value; // Membre privé pour stocker la valeur en virgule fixe.
		static const int _fractionnalBits = 8; // Nombre de bits de la partie fractionnaire.

	public:
		Fixed();  // Constructeur par défaut qui initialise la valeur à 0.
		Fixed (const Fixed &other); // Constructeur par recopie
		~Fixed(); // Destructeur

		Fixed(const int n);
		Fixed(const float f);
		
		Fixed &operator=(const Fixed &other); // Operateur d'affectation

		//6 opérateur de comparaison
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		//4 opérateurs de arithmétiques / rhs = right-hand side
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		//4 opérateurs d’incrémentation et de décrémentation (pre & post)
		Fixed	&operator++(void);//Pre-incrementation
		Fixed	operator++(int);//Post-incrementation
		Fixed	&operator--(void);
		Fixed	operator--(int);

			/*
		Static Function Members
		By declaring a function member as static, you make it independent of any
		 particular object of the class. A static member function can be called 
		 even if no objects of the class exist and the static functions are accessed
		 using only the class name and the scope resolution operator ::.

		A static member function can only access static data member, other static
		member functions and any other functions from outside the class.

		Static member functions have a class scope and they do not have access
		to the this pointer of the class. You could use a static member function
		to determine whether some objects of the class have been created or not.

		Une fonction membre statique est une fonction qui appartient à la classe elle-même
		plutôt qu'à une instance particulière de la classe.
		les fonctions min et max semblent être utilisées pour comparer deux objets Fixed
		et déterminer le minimum et le maximum entre eux. Ces opérations de comparaison
		ne nécessitent pas d'accéder à des données spécifiques de l'instance, elles
		peuvent donc être définies comme des fonctions statiques.
	*/
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		int		getRawBits(void) const; // Fonction membre pour obtenir la valeur brute sans conversion.
		void		setRawBits (int const raw); // Fonction membre pour initialiser la valeur brute.

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif