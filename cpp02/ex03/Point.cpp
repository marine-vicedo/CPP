/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:15:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 18:02:33 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	return ;
}

Point &Point :: operator=(const Point &other)
{
	(void) other;
	return (*this);
}

Point::~Point()
{
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
