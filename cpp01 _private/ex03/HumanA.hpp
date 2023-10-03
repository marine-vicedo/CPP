/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:36:35 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 14:01:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class HumanA
{
	private :
		std::string _name;
		// we use a reference here because Human A must have a weapon
		// a reference must be initialized when declared and cannot be changed
		Weapon &_weapon;
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack(void);
};

#endif