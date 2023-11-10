/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/02 11:44:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form	*createForm(std::string name, int gradeToSign, int gradeToExecute)
{
	try
	{
		Form	*form = new Form(name, gradeToSign, gradeToExecute);
		std::cout << *form << " has been successfully created." << std::endl;
		return (form);
	}
	catch(std::exception const & e)
	{
		std::cerr << RED "Exception: " << e.what() << NC << std::endl;
		return (NULL);
	}
}

Bureaucrat* createBureaucrat(std::string name, int grade)
{
	try 
	{
		Bureaucrat *bureaucrat = new Bureaucrat(name, grade);
		//std::cout << *bureaucrat << std::endl;
		return bureaucrat;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED "Exception: " << e.what() << NC << std::endl;
		return (NULL);
	}
}

int main(void)
{
	std::cout << std::endl << "----- Creating Forms -----\n";
	
	const int FormsNb = 5;
	Form *FormsList[FormsNb];

	FormsList[0] = createForm("Random form", 150, 1);
	FormsList[1] = createForm("Top Secret Form", 1, 1);
	FormsList[2] = createForm("Form 42", 42, 42);
	FormsList[3] = createForm("Unsignable Form", 0, 1);
	FormsList[4] = createForm("Unexecutable Form", 1, 0);

	std::cout << std::endl << "----- Laura Test -----\n";
	Bureaucrat *Laura = createBureaucrat("Laura", 3);
	if (Laura)
		for (int i = 0; i < FormsNb; i++)
			if(FormsList[i])
				Laura->signForm(*FormsList[i]);

	std::cout << std::endl << "----- Elise Test -----\n";
	Bureaucrat *Elise = createBureaucrat("Elise", 150);
	if (Elise)
		for (int i = 0; i < FormsNb; i++)
			if(FormsList[i])
				Elise->signForm(*FormsList[i]);

	std::cout << std::endl << "----- Anne Test -----\n";
	Bureaucrat *Anne = createBureaucrat("Anne", 1);
	if (Anne)
		for (int i = 0; i < FormsNb; i++)
			if(FormsList[i])
				Anne->signForm(*FormsList[i]);
			
	std::cout << std::endl << "----- Deleting Forms -----\n";
	for (int i = 0; i < FormsNb; i++)
		if(FormsList[i])
			delete (FormsList[i]);

	delete Laura;
	delete Elise;
	delete Anne;

	return 0;
	
}


