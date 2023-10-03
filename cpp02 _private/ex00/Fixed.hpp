/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:40:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/03 17:48:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		Fixed &operator=(const Fixed &other); // Operateur d'affectation
		~Fixed(); // Destructeur

		int getRawBits(void) const; // Fonction membre pour obtenir la valeur brute sans conversion.
		void setRawBits (int const raw); // Fonction membre pour initialiser la valeur brute.
};

#endif