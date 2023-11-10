/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:37:43 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/31 10:04:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm:: ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown")
{
	
}

ShrubberyCreationForm:: ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm:: ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm:: operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;
	return(*this);
}

ShrubberyCreationForm:: ~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm:: execute(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (getSigned() == false)
		throw FormNotSigned();
	std::cout << "A tree has been planted at " << _target << std::endl;
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "                           . ...                            " << std::endl;
	file << "                        .....:::                            " << std::endl;
	file << "                     ...:..::::.   .                        " << std::endl;
	file << "                    .:.:. - :.-... :.. .                    " << std::endl;
	file << "           .. . ..:..:.::-:-. ::..-:-....                   " << std::endl;
	file << "           .::....::..-=:-:=-::.--.-:....     .             " << std::endl;
	file << "           . ..::::..::=:::-.:=.=-:: ::.    ::.             " << std::endl;
	file << "          ....--.:----=+...=.-:+ ==::...:... ..             " << std::endl;
	file << "         ...-:- ::--==--*..:+:*::-. ::-:.   .:.::..         " << std::endl;
	file << "      .:::...-..:.-+===-+*..:=*=*  .::.:....:   ..:..       " << std::endl;
	file << "       ...:.:-=-=-.   :..=+-.:*==:---:-::-:-::::..          " << std::endl;
	file << "      ..  ...:-.:---...--:# *=#*: .::-::=-:..::..           " << std::endl;
	file << "  .       .-:..:..:=+=-:::%.= %:.:=-==::   ..-.             " << std::endl;
	file << " ...::  ...::--...=:. :--=%-- %:-*+-*-:=+---::.. . ...:.    " << std::endl;
	file << "  .:.:-::..::.-++-:::-:--:#*--%*==+::-:::-=-:..:.::. :      " << std::endl;
	file << "    :::+::::--.:..:---==::=% *#-.:==--:.:.: ...::+::: . ... " << std::endl;
	file << "  ....::==-:.:=: ....-----:%-%+:-==-:--:..-:-:--=:..::.:..  " << std::endl;
	file << "    :::. .::::.:----:::..--+%%#-..-=+++-:::.:==-:..:.       " << std::endl;
	file << "  ....:-:..-:   ...:===*=-:=%%*++===. .-=+***+==---         " << std::endl;
	file << "  ..  .:-=---==--:==-.:=*=-*%%= -..:==+*+=--=:...           " << std::endl;
	file << "   ::......:::....:+=+*++-=+%%..++**--+-:--==:.:.:..:::..   " << std::endl;
	file << "   .-= :-::.-=-:==.::-..:=**%%*+:::.:..:---.:==::::--:...   " << std::endl;
	file << "      :..:-+==-=+-*==*++=--*#%***+++=++--==-:.              " << std::endl;
	file << "         ......:  .      .-+**=       ...::::.              " << std::endl;
	file << "             .             =##:                             " << std::endl;
	file << "                           +%%.                             " << std::endl;
	file << "                           +%%:                             " << std::endl;
	file << "                           *%%-                             " << std::endl;
	file << "                          .%%%+                             " << std::endl;
	file << "                        .:*%%%%+.                           " << std::endl;
	file << "                        .:-:=::=:.                          " << std::endl;
	file.close();
}