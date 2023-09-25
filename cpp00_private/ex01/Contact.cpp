/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:37:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/18 15:14:38 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


// initialise chaque élément du tableau _informations avec une chaîne de caractères vide. Evite les erreurs de non-initialisation.
Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_informations[i] = std::string();
	return;
}

Contact::~Contact()
{
}

std::string Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

std::string	Contact::getFirstName() const
{
	return (this->_informations[FirstName]);
}

std::string	Contact::getLastName() const
{
	return (this->_informations[LastName]);
}

std::string	Contact::getNickName() const
{
	return (this->_informations[NickName]);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_informations[PhoneNumber]);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->_informations[DarkestSecret]);
}

bool	Contact::isNumeric(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

bool	Contact::isValidNumber(std::string str)
{
	if (!isNumeric(str))
	{
		this->_informations[PhoneNumber].clear();
		std::cout << RED "Invalid phone number. Please enter digits only." NC << std::endl;
		return (false);
	}
	return (true);
}

bool Contact::isSpace(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (std::isspace(str[i]))
			return (true);
	}
	return (false);
}

bool	Contact::set_contact()
{
	std::string input;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::_fields_name[i]<< " : " << std::flush;
		while ( !(std::getline(std::cin, this->_informations[i])) || this->_informations[i].length() == 0)//si la saisie echoue
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (this->_informations[i].length() == 0)
			{
				this->_informations[i].clear();
				std::cout << RED "Empty contact information not allowed." NC << std::endl;
				std::cout << "Please enter the " << Contact::_fields_name[i]<< " : " << std::flush;
			}
		}
		if (isSpace(this->_informations[i]) == true)
		{
			this->_informations[i].clear();
			std::cout << RED "No spaces or tabs are allowed." NC << std::endl;
			i--;
		}
		if (i == PhoneNumber && isValidNumber(this->_informations[i]) == false)
			i--;//si la saisie n'est pas valide, on revient a l'index precedent (i--) pour re-saisir le numero de telephone
	}
	std::cout << GREEN "Contact added successfully." NC << std::endl;
	return (true);
}


void	Contact::get_contact(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (this->_informations[i].length() > 10)
			std::cout << this->_informations[i].substr(0, 9) << ".";//substr(0, 9) = extrait une sous chaine de l'index 0 a 9 exclus puis ajoute "."
		else
			std::cout << std::setw(10) << this->_informations[i];
	}
	std::cout << "|" << std::endl;
}