/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:16 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/14 14:54:09 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"


void identify(Base *p)
{
	std::cout << CYAN "Identify Pointer : " NC ;
	if (dynamic_cast<A*>(p) != NULL)//si le cast a reussit
		std::cout << "A is the actual type\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B is the actual type\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C is the actual type\n";
	else
		std::cout << RED "Error: Unknown type" NC << std::endl;
	return;
}

void identify(Base &p)
{
	std::cout << CYAN "Identify Reference : " NC;
	try {
		(void)dynamic_cast<A&>(p);//conversion silencieuse : on passe en (void) car pas utilise dans la suite du code
		std::cout << "A is the actual type\n";}
	catch(const std::exception& e) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B is the actual type\n";}
	catch(const std::exception& e) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C is the actual type\n";}
	catch(const std::exception& e) {}
	
	return;
}

Base* generate(void)
{
	std::cout << std::endl << GREEN "Generate A, B or C" NC << std::endl;
	Base *basePtr = NULL;
	int random_val = std::rand();
	
	if (random_val % 2 == 0)
		basePtr = new A();
	else if (random_val % 3 == 0)
		basePtr = new B();
	else
		basePtr = new C();
	return (basePtr);
}

int main(void)
{
	Base *basePtr[10];
	for (int i = 0; i < 10; i++)
	{
		basePtr[i] = generate();
		identify(basePtr[i]);
		identify(*basePtr[i]);
		delete basePtr[i];
	}
	return (0);
}