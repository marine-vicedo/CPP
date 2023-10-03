/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 18:02:00 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"


int	main(void)
{
	Point const a(0, 0);
	Point const b(3, 6);
	Point const c(6, 0);

	{
		Point const point(4.1f, 2.1f);
	
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