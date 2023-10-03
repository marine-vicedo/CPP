/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:13:32 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 13:56:55 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bsp(Point const a, Point const b, Point const c, Point const p) : Cette fonction utilise l'aire
// des triangles pour déterminer si le point p se trouve à l'intérieur du triangle formé par a, b et c. Elle calcule l'aire de quatre triangles :

// areaTriangle : L'aire du triangle formé par a, b et c, calculée avec la fonction getTriangleArea.
// areaPAB : L'aire du triangle formé par p, a et b.
// areaPBC : L'aire du triangle formé par p, b et c.
// areaPAC : L'aire du triangle formé par p, a et c.
// Si p se trouve à l'intérieur du triangle, la somme des aires de areaPAB, areaPBC et areaPAC doit être égale à
// l'aire de areaTriangle. Si cette condition est vraie, la fonction renvoie true, ce qui signifie que le point est à l'intérieur du triangle.
// Sinon, elle renvoie false, ce qui signifie que le point est à l'extérieur du triangle.

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