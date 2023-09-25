/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:38:07 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/18 17:14:39 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

#define NC "\e[0m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#define RED "\e[31m"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_maxContacts;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	new_contact(void);
		void	show_phonebook(void)const;
		void	show_contact(void)const;
		void	show_contact_index(std::string input)const;
		void	show_options(void);
		void	welcome(void);
};

#endif
