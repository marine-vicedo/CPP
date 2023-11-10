/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:10:35 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 11:55:46 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		std::string const getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm &form);

	//Cette classe est une exception personnalisée qui est dérivée de std::exception. Elle est utilisée pour signaler une exception lorsqu'une tentative est faite pour définir un grade trop élevé pour le bureaucrate.
	//Elle redéfinit la fonction what() pour retourner un message d'erreur spécifique lorsqu'elle est attrapée.
	//what() est une fonction virtuelle pure définie dans la classe de base std::exception du C++. Elle est utilisée pour récupérer une chaîne de caractères (généralement un message d'erreur) associée à l'exception.
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
		
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif