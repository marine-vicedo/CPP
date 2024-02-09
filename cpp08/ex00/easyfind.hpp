/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:16:50 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/21 15:07:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <algorithm> //find
#include <iostream>

/*il faut mettre typename devant T:: lorsque qu'on parle de membres
dependant d'un template

iterator dépend du type T. Cela signifie que iterator peut être différent selon le type T utilisé.
pour un std::vector, T::iterator serait std::vector<int>::iterator,
pour un std::map, ce serait std::map<Key, Value>::iterator.

On doit utiliser typename pour indiquer explicitement au compilateur
que T::iterator est un type dependant du template.*/

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return (it);
	throw (std::out_of_range("Value not found in container"));//sous classe standard de std::exception
}

#endif