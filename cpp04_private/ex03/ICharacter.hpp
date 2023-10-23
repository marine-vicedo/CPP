/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/18 17:15:10 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

// Pour une classe abstraite en C++, vous n'êtes pas obligé de déclarer de constructeurs dans la classe elle-même. 
// Les classes abstraites sont conçues pour être utilisées comme des modèles ou des interfaces à partir desquels d'autres
// classes dérivées implémentent des fonctionnalités spécifiques. Par conséquent, les constructeurs et les destructeurs de
// la classe abstraite ne sont généralement pas déclarés ou implémentés, car ils ne sont pas pertinents pour l'interface générale.

// Cependant, il est important de noter que les classes dérivées de la classe abstraite doivent fournir leur propre implémentation
// de constructeurs si nécessaire pour leur propre initialisation. Les constructeurs dans les classes dérivées ne remplacent pas les
// constructeurs de la classe abstraite, car la classe abstraite ne peut pas être instanciée directement.

class AMateria;

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif