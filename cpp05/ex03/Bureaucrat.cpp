/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:51:53 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:33:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat:: Bureaucrat() : _name("Unknown"), _grade(75)
{
	std::cout << _name << " Bureaucrat has been created\n";
}

Bureaucrat:: Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << CYAN "A Bureaucrat named " << _name << " with grade " << _grade << " has been created\n" << NC;
}

Bureaucrat:: Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << CYAN "A copy of Bureaucrat has been created\n" << NC;
}

Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &other)
{
	std::cout << CYAN "Bureaucrat copy assignement operator called\n" << NC;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN << _name << " Bureaucrat has been destroyed\n" << NC;
}

std::string const Bureaucrat:: getName() const
{
	return (this->_name);
}

int Bureaucrat:: getGrade() const
{
	return (this->_grade);
}

void Bureaucrat:: incrementGrade()
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	std::cout << GREEN "Promoting " << _name << " to a higher grade" NC << std::endl;
	_grade -= 1;
}

void Bureaucrat:: decrementGrade()
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << GREEN "Downgrading " << _name << " to a lower grade" NC << std::endl;
	_grade += 1;
}

void Bureaucrat:: signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat:: executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Bureaucrat exception: grade too high" NC);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Bureaucrat exception: grade too low" NC);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << "Bureaucrat " << other.getName() << " (Grade: " << other.getGrade() << ")";
	return (os);
}