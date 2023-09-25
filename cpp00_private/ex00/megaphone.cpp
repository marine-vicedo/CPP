/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:25:40 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 11:30:01 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//toupper renvoie la valeur ASCII donc on cast en char

#include <iostream>

int	main(int ac, char **av)
{
	int i;
	int j;
	
	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while(av[i][j])
				std::cout << (char)std::toupper(av[i][j++]);
			// if (i != ac - 1)
			// 	std::cout << " ";
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
