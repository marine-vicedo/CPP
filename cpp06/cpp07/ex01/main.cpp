/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:14:22 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/17 11:23:56 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void)
{
	{
		int arrayInt[4] = {2, 5, 9, 76};
		size_t size = 4;
		iter(arrayInt, size, printArray<int>);
	}
	std::cout << std::endl;
	{
		std::string arrayStr[4] = {"hello", "world", "42", "toto"};
		size_t size = 4;
		iter(arrayStr, size, printArray<std::string>);
	}

	return (0);
}

/*-------------------------------------------*/

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x )
// { std::cout << x << std::endl; return; }

// int main()
// {
// 	int tab[] = { 0, 1, 2, 3, 4 };
// 	Awesome tab2[5];
// 	iter(tab, 5, print<int>);
// 	iter(tab2, 5, print<Awesome>);
// 	return 0;
// }
