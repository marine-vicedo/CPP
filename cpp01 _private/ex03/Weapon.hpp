/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:25:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/08/22 15:45:18 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private :
		std::string _type;
	public :
		Weapon(std::string weaponType);
		~Weapon();
		//getType() returns a reference to a constant string
		std::string const &getType(void);
		//setType() takes a reference to a constant string
		void setType(std::string weaponType);
};

#endif