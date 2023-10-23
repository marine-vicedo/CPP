/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:04:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 14:13:13 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const	Animal *meta = new Animal();
		const	Animal *j = new Dog();
		const	Animal *i = new Cat();
		const	Dog	*dog = new Dog();
		
		std::cout << "Quel est le type ? : "<< j->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << i->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << meta->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << dog->getType() << " " << std::endl;

		std::cout << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		dog->makeSound();

		std::cout << std::endl;
		delete j;
		delete i;
		delete meta;
		delete dog;
	}

	{
		std::cout << std::endl;
		const	WrongAnimal *wrongmeta = new WrongAnimal();
		const	WrongAnimal *y = new WrongDog();
		const	WrongAnimal *z = new WrongCat();

		std::cout << "Quel est le type ? : "<< y->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << z->getType() << " " << std::endl;

		std::cout << std::endl;
		z->makeSound();
		y->makeSound();
		wrongmeta->makeSound();

		std::cout << std::endl;
		delete y;
		delete z;
		delete wrongmeta;
	}
	
	return (0);
}