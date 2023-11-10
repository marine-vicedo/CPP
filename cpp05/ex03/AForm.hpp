/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:44:33 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 13:31:32 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		AForm();
		AForm(std::string const name, int const gradeToSign, int const GradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		std::string const getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		int getSigned() const;
		virtual void execute(Bureaucrat &bureaucrat) = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &Form);

#endif