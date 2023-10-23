/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:56:04 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 12:02:19 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void	subject_main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	
	me->equip(tmp);
	tmp = src->createMateria("cure");
	
	std::cout << std::endl;
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;
}

void testCharacters(void)
{
	std::cout << std::endl
			  << "-------------------------------" << std::endl
			  << "    WELCOME TO THE EPIC DUEL" << std::endl
			  << "-------------------------------" << std::endl;
	std::cout << std::endl
			  << "-- CREATING MATERIA SOURCE" << std::endl;
	MateriaSource *source = new MateriaSource();
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	std::cout << std::endl
			  << "-- MATERIA SOURCE CREATES ITEMS ON THE FLOOR" << std::endl;
	int nb_items = 6;
	AMateria *materias[nb_items + 1];
	materias[nb_items] = NULL;

	std::cout << "-- Creating an array of " << nb_items << " materias." << std::endl;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			materias[i] = source->createMateria("ice");
		else
			materias[i] = source->createMateria("cure");
	}
	std::cout << std::endl;

	std::cout << std::endl
			  << "-- CREATING CHARACTERS" << std::endl;
	Character *swan = new Character("Swan");
	Character *eagle = new Character("Eagle");

	std::cout << std::endl
			  << "-- EQUIPPING CHARACTERS" << std::endl;
	for (int i = 0; i < nb_items / 2; i++)
		swan->equip(materias[i]);
	for (int i = nb_items / 2; i < nb_items; i++)
		eagle->equip(materias[i]);

	swan->displayInventory();
	eagle->displayInventory();
	eagle->unequip(2);
	eagle->displayInventory();

	std::cout << std::endl
			  << "-- 3, 2, 1, 0! FIGHT!" << std::endl;
	eagle->use(3, *swan);
	swan->use(2, *swan);
	swan->use(1, *eagle);
	swan->use(1, *eagle);
	eagle->use(1, *eagle);
	eagle->use(2, *swan);
	eagle->use(1, *swan);
	swan->use(0, *eagle);

	std::cout << std::endl
			  << "-- CHARACTER DELETION" << std::endl;
	delete swan;
	delete eagle;

	std::cout << std::endl
			  << "-- MATERIA SOURCE DELETION" << std::endl;
	delete source;
}

int main()
{
	subject_main();
	testCharacters();
}