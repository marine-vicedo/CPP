/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:15:02 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 12:01:03 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form:: Form() : _name("Default"), _isSigned(false), _gradeToSign(30), _gradeToExecute(50)
{
	std::cout << "A " << _name << " has been created" << std::endl;
}

Form:: Form(std::string const name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
	std::cout << "A " << _name << " has been created" << std::endl;
}

Form:: Form(const Form &other) :
	_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "A copy of " << _name << " has been created" << std::endl;
}

Form &Form:: operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << "Copy assignement operator is called\n";
	return (*this);
}

Form:: ~Form()
{
	std::cout << "Form has been destroyed\n";
}

std::string const Form:: getName() const
{
	return (this->_name);
}

int Form:: getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form:: getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form:: beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade()> _gradeToSign)
		throw (Form::GradeTooLowException());
	_isSigned = true;
	return ;
		
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (RED "Form exception: grade too high" NC);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (RED "Form exception: grade too low" NC);
}

std::ostream &operator<<(std::ostream &os, Form const &Form)
{
	os << Form.getName() << " (" << Form.getGradeToSign() << ", "<< Form.getGradeToExecute() << ")";
	return (os);
}