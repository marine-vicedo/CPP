/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:47:33 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/17 11:42:16 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstddef>

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		
		Array(const Array<T> &other);
		Array &operator=(const Array<T> &other);
		T &operator[](const int idx) const;

		~Array();
		size_t size() const;
		class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Index is out of bounds";}
	};
};

template <typename T>
std::ostream& operator<<( std::ostream& out, const Array<T>& arr );
#include "Array.tpp"

#endif