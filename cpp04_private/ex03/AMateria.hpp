/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:26 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 14:55:13 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

#define	NC "\e[0m"
#define ORANGE "\e[38;5;208m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

#include "ICharacter.hpp"

//déclaration anticipée de class ICharacter; indique au compilateur que la classe ICharacter
//sera définie ultérieurement, et il peut donc compiler le reste du code dans AMateria.hpp en utilisant cette déclaration.
//necessaire pour les dependances circulaires (cf AMateria.hpp)
class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		AMateria();

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif