/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:22:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/20 15:31:16 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void _debug();
		void _info();
		void _warning();
		void _error();
		
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#define RED  "\033[1;91m"
#define MAGENTA "\033[1;95m"
#define GREEN  "\033[1;92m"
#define CYAN  "\033[1;96m"
#define NC  "\033[0;39m"

#endif