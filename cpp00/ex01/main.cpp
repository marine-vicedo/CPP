/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:31:37 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 11:33:12 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook 	PhoneBook;
	bool		launch = true;
	std::string	input;

	PhoneBook.welcome();
	PhoneBook.show_options();
	while (launch && std::getline(std::cin, input))
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		else if (input.compare("ADD") == 0)
			PhoneBook.new_contact();
		else if (input.compare("SEARCH") == 0)
		{
			PhoneBook.show_phonebook();
			PhoneBook.show_contact();
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Good Bye." << std::endl;
			launch = false;
			continue ;
		}
		input.clear();
		PhoneBook.show_options();
	}
	if (launch == true)
		std::cout << "You pressed ^D, exiting now." << input << std::endl;
	return (0);
}