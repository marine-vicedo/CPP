/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:04:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:14:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
		const	AAnimal *j = new Dog();
		const	AAnimal *i = new Cat();
		const	Dog	*dog = new Dog();

		std::cout << "Quel est le type ? : "<< j->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << i->getType() << " " << std::endl;
		std::cout << "Quel est le type ? : " << dog->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		dog->makeSound();

		delete j;
		delete i;
		delete dog;
		
		// const	AAnimal *meta = new AAnimal();
		// std::cout << "Quel est le type ? : " << meta->getType() << " " << std::endl;
		// meta->makeSound();
		// delete meta;
	
	return (0);
}