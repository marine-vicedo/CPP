/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 17:18:51 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette fonction calcule l'aire du triangle formé par les points a, b et c en utilisant la formule de
//l'aire d'un triangle basée sur les coordonnées des points. La formule est la suivante :

//aire_triangle = |(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()))| / 2
//|...| représente la valeur absolue de l'expression pour s'assurer que l'aire est positive.

#include "Point.hpp"
#include "Fixed.hpp"


int	main(void)
{
	Point const a(0, 0);
	Point const b(3, 6);
	Point const c(6, 0);

	{
		Point const point(4.1f, 2.1f);//f pour indiquer au compilateur qu'il s'agit d'un flottant et non d'un double.
	
		if (bsp (a, b, c, point) == true)
			std::cout << "The point is inside the triangle" << std::endl;
		else
			std::cout << "The point is outside the triangle" << std::endl;
	}

	{
		Point const point(0, 0);
	
		if (bsp (a, b, c, point) == true)
			std::cout << "The point is inside the triangle" << std::endl;
		else
			std::cout << "The point is outside the triangle" << std::endl;
	}

	{
		Point const point(2, 2);

		if (bsp (a, b, c, point) == true)
			std::cout << "The point is inside the triangle" << std::endl;
		else
			std::cout << "The point is outside the triangle" << std::endl;
	}

	return (0);	
}