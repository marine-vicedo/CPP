/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:15:02 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:32:16 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm:: AForm() : _name("Default"), _isSigned(false), _gradeToSign(30), _gradeToExecute(50)
{
	std::cout << CYAN "A " << _name << " has been created" NC << std::endl;
}

AForm:: AForm(std::string const name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << CYAN "A " << _name << " has been created" NC << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm:: AForm(const AForm &other) :
	_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << CYAN "A copy of " << _name << " has been created" NC << std::endl;
}

AForm &AForm:: operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << CYAN "Copy assignement operator is called" NC << std::endl;
	return (*this);
}

AForm:: ~AForm()
{
	std::cout << CYAN "A " << _name << " has been destroyed" NC << std::endl;
}

std::string const AForm:: getName() const
{
	return (this->_name);
}

int AForm:: getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm:: getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm:: beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade()> _gradeToSign)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
	return ;
		
}

int AForm:: getSigned() const
{
	return (_isSigned);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (RED "AForm exception: grade too high" NC);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (RED "AForm exception: grade too low" NC);
}

const char* AForm::FormNotSigned::what() const throw()
{
	return (RED "AForm exception: form not signed" NC);
}

std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
	os << AForm.getName() << " (" << AForm.getGradeToSign() << ", "<< AForm.getGradeToExecute() << ")";
	return (os);
}