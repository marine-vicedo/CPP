/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:37:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 11:38:13 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define NC "\e[0m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#define RED "\e[31m"

class Contact
{
	private:
		static std::string	_fields_name[5];
		std::string			_informations[5];

		enum Field
		{
			FirstName = 0,
			LastName = 1,
			NickName = 2,
			PhoneNumber = 3,
			DarkestSecret = 4
		};

	public:
		Contact(void);
		~Contact(void);

		std::string	getFirstName()const;
		std::string	getLastName()const;
		std::string	getNickName()const;
		std::string	getPhoneNumber()const;
		std::string	getDarkestSecret()const;
		bool	set_contact();
		void	get_contact(int index)const;
		bool	isNumeric(std::string str);
		bool	isValidNumber(std::string str);
		bool	isSpace(std::string str);
};

#endif