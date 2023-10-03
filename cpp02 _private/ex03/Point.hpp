/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:06:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 14:05:45 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();
		Fixed const	& getX() const;//getters qui retourne des references constantes
		Fixed const	& getY() const;
	
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif