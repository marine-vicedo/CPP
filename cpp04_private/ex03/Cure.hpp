/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:37:42 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/17 14:38:27 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
		std::string _type;

	public:
		Cure();
		Cure(const Cure&other);
		Cure &operator=(const Cure&other);
		~Cure();

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif