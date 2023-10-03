/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:40:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/09/28 17:42:03 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std ::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std ::cout << std::endl;

	std::cout << b << std::endl;
	std ::cout << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std ::cout << std::endl;

	Fixed const c(5);
	std::cout << c + b << std::endl;
	std ::cout << std::endl;
	std::cout << c - b  << std::endl;
	std ::cout << std::endl;
	std::cout << c * b << std::endl;
	std ::cout << std::endl;
	std::cout << c / b << std::endl;
	std ::cout << std::endl;
	return 0;
	
	return 0;
}