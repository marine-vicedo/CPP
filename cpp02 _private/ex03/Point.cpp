/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:15:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 13:59:21 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	//std::cout << CYAN "Point : Default constructor called" NC << std::endl;
	return ;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	//std::cout << CYAN "Point : constructor called" NC << std::endl;
	return ;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	//std::cout << CYAN "Point : Copy constructor is called" NC << std::endl;
	//*this = other;
}

Point &Point :: operator=(const Point &other)
{
	//std::cout << YELLOW "Point : Copy assignement is called" NC << std::endl; 
	// if (this != &other)
	(void) other;
	return (*this);
}

Point::~Point()
{
	//std::cout << CYAN "Point : Destructor is called" NC << std::endl;
	return ;
}

Fixed const &Point :: getX (void) const
{
	return (this->_x);
}

Fixed const &Point:: getY (void) const
{
	return (this->_y);
}
