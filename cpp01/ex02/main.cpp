/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:20:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 16:07:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl;
	std::cout << "Address of string in memory: " << &str << std::endl;
	std::cout << "Address stored in stringPTR (pointer): " << stringPTR << std::endl;
	std::cout << "Address stored in stringREF (reference): " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value pointed by stringPTR (pointer): " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF (reference): " << stringREF << std::endl << std::endl;

	return (0);
}