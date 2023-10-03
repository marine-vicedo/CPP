/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:13:32 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 17:59:44 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	abs(Fixed area)
{
	if (area < 0)
		return (area * - 1);
	return (area);
}

Fixed	getTriangleArea(Point a, Point b, Point c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaTriangle;
	Fixed	areaPAB;
	Fixed	areaPBC;
	Fixed	areaPAC;
	
	areaTriangle = abs(getTriangleArea(a, b, c));
	areaPAB = abs(getTriangleArea(point, a, b));
	areaPBC = abs(getTriangleArea(point, b, c));
	areaPAC = abs(getTriangleArea(point, a, c));

	if (areaPAB != 0 && areaPBC != 0 && areaPAC != 0 && 
		areaPAB + areaPBC + areaPAC <= areaTriangle)
			return (true);
	return (false);
}