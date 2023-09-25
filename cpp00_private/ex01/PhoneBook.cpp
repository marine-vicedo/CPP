/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:37:47 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/18 19:07:48 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)//constructeur par defaut
{
	this->_index = 0;
	this->_maxContacts = 0;
}

PhoneBook::~PhoneBook(void)
{
	
}

void	PhoneBook::new_contact(void)
{
	std::string input;
	std::cout << "Contact #" << this->_index + 1 << std::endl;
	if (this->_contacts[this->_index].set_contact() == true)//creation nouvelle instance de la classe Contact puis appel de set.contact
	{
		this->_index++;
		if (this->_index > 7)
			this->_index = 0;
		if (this->_maxContacts < 8)
			this->_maxContacts++;
	}
}

void PhoneBook::show_phonebook() const
{
	if (this->_maxContacts == 0)
	{
		std::cout << "No contact to display" << std::endl;
		return;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_maxContacts; i++)
		this->_contacts[i].get_contact(i + 1);
	std::cout << "|-------------------------------------------|" << std::endl;
}


void	PhoneBook::show_contact() const
{
	std::string input;

	if (this->_maxContacts == 0)
		return;
	if (this->_maxContacts > 0)
	{
		std::cout << "Please enter the contact index: " << std::flush;
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input[0] < '1' || input[0] > '8' || (input[0] - '0') > this->_maxContacts)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input[0] < '1' || input[0] > '8' )
			{
				std::cin.clear();
				std::cout << RED "Only digits in range of 1 to 8 are allowed.\n" NC;
				std::cout << "Please enter the contact index: " << std::flush;
			}
			else if ((input[0] - '0') > this->_maxContacts)
			{
				std::cin.clear();
				std::cout << YELLOW "You only have " << this->_maxContacts << " Contacts saved." NC << std::endl;
				std::cout << "Please enter the contact index: " << std::flush;
			}
		}
	}
	show_contact_index(input);
}

void	PhoneBook::show_contact_index(std::string input) const
{
	int index;
	index = input[0] - '0';//convert string to int
	if (index > 0)
	{
		std::cout << "First Name: " << this->_contacts[index - 1].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index - 1].getNickName() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[index - 1].getDarkestSecret() << std::endl;
	}
}

void	PhoneBook::welcome(void)
{
	std::cout << std::endl;
	std::cout << MAGENTA "Welcome to your phonebook." NC << std::endl;
	std::cout << std::endl;
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "ADD : Add a new contact." << std::endl;
	std::cout << "SEARCH : Search for a contact." << std::endl;
	std::cout << "EXIT : Exit phonebook." << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::show_options(void)
{
	std::cout << GREEN "Enter your command [ADD, SEARCH, EXIT]: " NC << std::flush;
}
