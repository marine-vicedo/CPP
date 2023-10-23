/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:04:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:13:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER 6

int	main(void)
{
	{
		std::cout << std::endl;
		Animal *animalGroup[NUMBER];

		for (int i = 0; i < NUMBER; i++)
		{
			if (i < (NUMBER / 2))
				animalGroup[i] = new Cat();
			else
				animalGroup[i] = new Dog();
		}
		std::cout << std::endl;
		for (int i = 0; i < NUMBER; i++)
			delete animalGroup[i];
	
	}
	
	std::cout << std::endl;
	
	{
		Cat *c = new Cat();
	
		for (int i = 0; i < 100; i++)
			std::cout << c->getBrain()->getIdeas(i) << std::endl;

		delete c;
	}
	
	std::cout << std::endl;

	{
		Cat kitty;
		Cat &kitty_ref = kitty;

		for (int i = 0; i < 100; i++)
	 		std::cout << kitty.getBrain()->getIdeas(i) << std::endl;
		std::cout << std::endl;
		Cat kitty_cpy(kitty_ref);
		for (int i = 0; i < 100; i++)
	 		std::cout << kitty_cpy.getBrain()->getIdeas(i) << std::endl;
		std::cout << std::endl;

		std::cout << "Cat Kitty adress : " << &kitty << std::endl;
		std::cout << "Cat Kitty_cpy adress : " << &kitty_cpy << std::endl;
	}
	
	return (0);
}