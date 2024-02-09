/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:03:25 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/22 14:17:17 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SPAN_SIZE 10

int main(void)
{
	{
		std::cout << CYAN "----> Subject example <----" NC << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << CYAN "----> Error test <----" NC << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Span sp = Span(2);
			sp.addNumber(6);
			sp.addNumber(7);
			sp.addNumber(8);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << CYAN "----> AddRange test <----" NC << std::endl;
		Span sp(SPAN_SIZE);
		std::vector<int> numbersToAdd;
		for (unsigned int i = 0; i < SPAN_SIZE; i++)//test SIZE + 1
			numbersToAdd.push_back(std::rand() % 201 - 100);//Génère des valeurs entre 0 et 200 puis décale la plage vers -100
			
		std::vector<int>::iterator begin = numbersToAdd.begin();
		std::vector<int>::iterator end = numbersToAdd.end();

			std::cout << "Adding numbers to span: ";
		for (std::vector<int>::iterator it = begin; it != end; ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		
		try
		{
			sp.addRange<std::vector<int> >(begin, end);
			std::cout << GREEN "OK. Number range successfully added to span." NC << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED "Exception: Cannot add range of " << SPAN_SIZE 
				<< " numbers: " << e.what() 
				<< " (Max range size is " << SPAN_SIZE
				<< " elements)." NC << std::endl << std::endl;
		}
		try
		{
			std::cout << CYAN "----> shortest/longest span test <----" NC << std::endl;
			std::cout << "minSpan : " << sp.shortestSpan() << std::endl;
			std::cout << "maxSpan : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED "Exception: " << e.what() << NC << std::endl << std::endl;
		}
	}
	{
		std::cout << CYAN "----> Deep copy test <----" NC << std::endl;
		try
		{
			Span sp1(2);
			sp1.addNumber(5);
			sp1.addNumber(67);
			std::cout << "Elements in the Span sp1: " << sp1 << std::endl;

			Span sp2(4);
			sp2.addNumber(99);
			sp2.addNumber(34);
			sp2.addNumber(4);
			sp2.addNumber(78);
			std::cout << "Elements in the Span sp2: " << sp2 << std::endl;
			sp1 = sp2;
			std::cout << "Elements in the Span sp1: " << sp1 << std::endl;
			
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return 0;
}