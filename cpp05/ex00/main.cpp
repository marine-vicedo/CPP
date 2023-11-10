/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:38:18 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat* createBureaucrat(std::string name, int grade)
{
	try 
	{
		Bureaucrat *bureaucrat = new Bureaucrat(name, grade);
		std::cout << *bureaucrat << std::endl;
		return bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

void	upGrades(Bureaucrat *B)
{
	try 
	{
		std::cout << std::endl << *B << " is requesting a promotion"<< std::endl;
		B->incrementGrade();
		std::cout << "Bureaucrat: " << B->getName() << " has been promoted to Grade: " << B->getGrade() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	downGrades(Bureaucrat *B)
{
	try 
	{
		
		std::cout << std::endl << *B << " has been blamed"<< std::endl;
		B->decrementGrade();
		std::cout << "Bureaucrat " << B->getName() << " has been downgraded to Grade: " << B->getGrade() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	{
		std::cout << std::endl << "----- Bureaucrats with good grades -----\n";
		const int numGoodBureaucrats = 3;
		Bureaucrat* goodBureaucrats[numGoodBureaucrats];

		goodBureaucrats[0] = createBureaucrat("Jane", 2);
		goodBureaucrats[1] = createBureaucrat("Will", 3);
		goodBureaucrats[2] = createBureaucrat("Maria", 150);

		std::cout << std::endl << "----- Upgrades -----\n";
		for (int i = 0; i < numGoodBureaucrats; i++)
			if (goodBureaucrats[i])
				upGrades(goodBureaucrats[i]);
			
		std::cout << std::endl << "----- downgrades -----\n";
		for (int i = 0; i < numGoodBureaucrats; i++)
			if (goodBureaucrats[i])
				downGrades(goodBureaucrats[i]);
			
		std::cout << std::endl;
		for (int i = 0; i < numGoodBureaucrats; i++)
			if (goodBureaucrats[i])
				delete goodBureaucrats[i];
	}

	{
		std::cout << std::endl << "----- Bureaucrats with wrong grades -----\n";
		const int numBadBureaucrats = 3;
		Bureaucrat* badBureaucrats[numBadBureaucrats];

		badBureaucrats[0] = createBureaucrat("John", 151);
		badBureaucrats[1] = createBureaucrat("Karen", 0);
		badBureaucrats[2] = createBureaucrat("Harl", -1);

		for (int i = 0; i < numBadBureaucrats; i++)
			if (badBureaucrats[i])
				delete badBureaucrats[i];
	}
	
	{
		std::cout << std::endl  << "-----  Test : Copy Bureaucrats -----\n";
		try
		{
			Bureaucrat Anna("Anna", 6);
			std::cout << Anna << std::endl;
			Bureaucrat Lea("Lea", 72);
			std::cout << Lea << std::endl;
			Lea = Anna;
			std::cout << Lea << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}


