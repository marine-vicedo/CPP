/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:28:22 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:34:02 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern:: Intern()
{
	std::cout << PURPLE "An Intern has been created" NC << std::endl;
}


Intern:: Intern(const Intern &other)
{
	(void)other;
	std::cout << PURPLE "A copy of Intern has been created" NC << std::endl;
}

Intern &Intern:: operator=(const Intern &other)
{
	(void)other;
	std::cout << PURPLE "Intern Assignement copy operator" NC << std::endl;
	return (*this);
}

Intern:: ~Intern()
{
	std::cout << PURPLE "An Intern has been destroyed" NC << std::endl;
}

const char* Intern::InvalidFormName::what() const throw()
{
	return (RED "Intern exception : invalid form name" NC);
}

static AForm *newShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *newRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *newPresidential(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *internForm = NULL;

	const std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	typedef AForm *(*FormConstructorPtr)(const std::string);
	FormConstructorPtr form_constructors[3] = {&newShrubbery, &newRobotomy, &newPresidential};

	for (int i = 0; i < 3; i ++)
	{
		if (formName == form_names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			internForm = form_constructors[i](target);
			break;
		}
	}
	if (!internForm)
	{
		std::cout << "Intern couldn't create " << formName << " form" << std::endl;
		throw (InvalidFormName());
	}
	return (internForm);
}