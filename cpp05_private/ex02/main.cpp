/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 12:05:51 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try
	{
		std::cout << "\n--------------- Bureaucrats ---------------" << std::endl;
		Bureaucrat Anne("Anne", 3);
		Bureaucrat Elise("Elise", 35);
		Bureaucrat Laura("Laura", 138);
		Bureaucrat Melo("Melo", 65);
		Melo = Anne;
		std::cout << Melo << std::endl;
		
		std::cout << "\n--------------- Forms ---------------" << std::endl;
		ShrubberyCreationForm form1("WeirdGarden");
		std::cout << form1 << std::endl;
		RobotomyRequestForm form2("Robotomy Rob");
		PresidentialPardonForm form3("High President");

		std::cout << "\n--------------- Form 1 ( Shrubbery : sign 145, execute 137 ) ---------------" << std::endl;
		Anne.signForm(form1);
		Anne.executeForm(form1);
		std::cout << "\n";
		Elise.signForm(form1);
		Elise.executeForm(form1);
		std::cout << "\n";
		Laura.signForm(form1);
		Laura.executeForm(form1);
		Laura.incrementGrade();
		Laura.signForm(form1);
		Laura.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy : sign 72, execute 45) ---------------" << std::endl;
		Elise.signForm(form2);
		Elise.executeForm(form2);
		Elise.executeForm(form2);
		Laura.signForm(form2);
		Laura.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President : sign 25, execute 5) ---------------" << std::endl;
		Anne.executeForm(form3);
		Anne.signForm(form3);
		Anne.executeForm(form3);
		std::cout << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}


