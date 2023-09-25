/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:31:37 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/18 19:00:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook 	PhoneBook;//declaration d'un objet PhoneBook, appel implicite du constructeur
	bool		launch = true;
	std::string	input;

	PhoneBook.welcome();
	PhoneBook.show_options();
	while (launch && std::getline(std::cin, input))
	{
		if (std::cin.eof() == true)//eof ; fin de fichier ou CTRL+D
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
			launch = false;//condition de sortie de la boucle
			continue ;//saute la suite du code et revient au debut de la boucle (while(...)) pour la prochaine iteration
		}
		input.clear();// réinitialiser la chaîne de caractères input afin de la préparer pour une nouvelle saisie utilisateur.
		PhoneBook.show_options();
	}
	if (launch == true)
		std::cout << "You pressed ^D, exiting now." << input << std::endl;
	return (0);
}

//En résumé, cette condition if (launch) permet de différencier deux cas :
//si launch est vrai à la fin du programme, cela signifie que le programme se termine de manière inattendue (par exemple, en appuyant sur Ctrl+D),
//et si launch est faux à la fin du programme, cela signifie que l'utilisateur a explicitement entré "EXIT" pour quitter le programme.