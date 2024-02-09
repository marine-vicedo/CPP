/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/16 16:28:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T, typename F>
void iter(T array[], size_t size, F ft_function)
{
	for (size_t i = 0; i < size; i++)
		ft_function(array[i]);
	return;
}

template <typename T>
void printArray(T &element)
{
	std::cout << element << std::endl;
}

#endif