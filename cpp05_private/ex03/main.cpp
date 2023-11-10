/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:49:17 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	InternFormCreation(std::string formName, std::string target)
{
	std::cout << std::endl << "---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	InternStud = Intern();
	Bureaucrat Anne("Anne", 1);
	AForm *	form;
	try
	{
		form = InternStud.makeForm(formName, target);
		Anne.signForm(*form);
		Anne.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << NC << std::endl;
	}
}

int	main(void)
{
	InternFormCreation("shrubbery creation", "WeirdGarden");
	InternFormCreation("robotomy request", "Robot Rob");
	InternFormCreation("presidential pardon", "Mr.Snow");
	InternFormCreation("white form", "John D");
	return (0);
}

