/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:02:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/08 18:38:29 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./prog <argument>" << std::endl;
		return (1);
	}
	ScalarConverter::setType(av[1]);
	ScalarConverter::convert(av[1]);
	ScalarConverter::printAll();
	return (0);
}