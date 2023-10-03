/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:28:31 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/26 15:58:55 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void Harl::_debug()
{
	std::cout << GREEN << "[DEBUG]" << NC << std::endl 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do !\n" << std::endl;
	return;
}

void Harl::_info()
{
	std::cout << CYAN << "[INFO]" << NC << std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put "
	"enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
	return ;
}

void Harl::_warning()
{
	std::cout << MAGENTA << "[WARNING]" << NC << std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming "
	"for years whereas you started working here since last month.\n" << std::endl;
	return ;
}

void Harl::_error()
{
	std::cout << RED << "[ERROR]" << NC << std::endl
	<< "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
	return ;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case 0:
			this->_debug();
			index++;
		case 1:
			this->_info();
			index++;
		case 2:
			this->_warning();
			index++;
		case 3:
			this->_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return;
}