/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:45:12 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:52:38 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm:: PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Unknown")
{
}

PresidentialPardonForm:: PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm:: PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(const PresidentialPardonForm &other)
{
	_target = other._target;
	return(*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
}

void PresidentialPardonForm:: execute(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (getSigned() == false)
		throw FormNotSigned();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
