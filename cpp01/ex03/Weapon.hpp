/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:25:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 16:08:11 by mvicedo          ###   ########.fr       */
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
		std::string const &getType(void);
		void setType(std::string weaponType);
};

#endif