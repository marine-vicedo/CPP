/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:40:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 14:40:24 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Les nombres en virgule flottante peuvent ainsi être vus comme l’équivalent informatique de la notation scientifique.

int main (void)
{
	//std::cout << "Instance A " << std::endl;
	Fixed a; //crée une instance de la classe Fixed nommée a en utilisant le constructeur par défaut.
	//std::cout << "Instance B " << std::endl;
	Fixed b(a); //crée une autre instance de la classe Fixed nommée b en utilisant le constructeur de recopie. Le constructeur de recopie copie la valeur de l'instance a dans b.
	//std::cout << "Instance C " << std::endl;
	Fixed c;

	c = b;//affecte la valeur de l'instance b à l'instance c en utilisant l'opérateur d'affectation (operator=) de la classe Fixed. Le constructeur d'affectation copie la valeur de b dans c.

	//std::cout << "Get Raw Bits" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	a.setRawBits(46); 
	std::cout << a.getRawBits() << std::endl;

	return 0;
}