/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:50:24 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 11:24:47 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_leftMateria[4];
		Character();
	public:
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
	
		std::string const &getName() const;
		void setName(std::string const & newName);
		
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		void initInventory(AMateria *inventory[4]);
		void deleteInventory(AMateria *inventory[4]);
		void displayInventory() const;
		void initUnequipTab(AMateria *leftMateria[4]);
		void deleteUnequipTab(AMateria *leftMateria[4]);
		
};

#endif