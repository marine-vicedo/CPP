/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:39:07 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 17:32:33 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<< GREEN "Program usage is : ./HarlFilter <level>" NC <<std::endl;
		std::cout<< CYAN "Levels are : DEBUG or INFO or WARNING or ERROR" NC<<std::endl;
		return 0;
	}
	
	Harl harl;
	std::string input;

	input = av[1];

	harl.complain(input);

	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
	// harl.complain("BLABLA");
}