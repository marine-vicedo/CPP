/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:51:12 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:14:14 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain:: Brain()
{
	std::cout << PURPLE "Brain constructor is called" NC << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "I have an idea";
	return ;
}

Brain:: Brain(const Brain &other)
{
	std::cout << PURPLE "Brain copy constructor is called" NC << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i] + " but it's not mine, I've copied it";
	return ;
}

Brain &Brain:: operator=(const Brain &other)
{
	std::cout << PURPLE "Brain assignement copy operator is called" NC << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i] + " but it's not mine, I've copied it";
	}
	return (*this);
}

Brain:: ~Brain()
{
	std::cout << PURPLE "Brain destructor is called" NC << std::endl;
	delete [] this->_ideas;
	return ;
}

std::string Brain:: getIdeas(int n) const
{
	return(this->_ideas[n]);
}