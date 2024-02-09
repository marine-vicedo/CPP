/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/21 15:15:07 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*std::find() pour les conteneurs séquentiels
et std::map::find() pour les conteneurs associatifs comme std::map

std::find() : prend en paramètres 2 itérateurs (begin et end) et la valeur à rechercher.
template< class InputIt, class T >
InputIt find( InputIt first, InputIt last, const T& value );

std::map::find() : pour rechercher une clé spécifique 
iterator find( const Key& key );
const_iterator find( const Key& key ) const;
*/

#include "easyfind.hpp"

int main(void)
{
	{
		std::vector<int> array;
		array.push_back(2);
		array.push_back(67);
		array.push_back(93);
		array.push_back(42);
		for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		try
		{
			std::vector<int>::iterator result = easyfind(array, 67);
			std::cout << "Find value : " << *result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::vector<int>::iterator result = easyfind(array, -7);
			std::cout << "Find value : " << *result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::list<int> list;
		list.push_back(88);
		list.push_front(45);
		list.push_back(9);
		list.push_front(12);
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		try
		{
			std::list<int>::iterator result = easyfind(list, 88);
			std::cout << "Find value : " << *result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::list<int>::iterator result = easyfind(list, 0);
			std::cout << "Find value : " << *result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}