/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:58 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:53:30 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
{

}

RobotomyRequestForm:: RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	
}

RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm:: operator=(const RobotomyRequestForm &other)
{
	_target = other._target;
	return(*this);
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm:: execute(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (getSigned() == false)
		throw FormNotSigned();
	static int i;
	if (i % 2 ==  0)
		std::cout << "Bzzzzt Bzzzt " << _target << " has been robotomized\n";
	else
		std::cout << "Hmm it failed, try again\n";
	i++;
}