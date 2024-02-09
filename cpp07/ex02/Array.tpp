/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:41:56 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/17 11:42:49 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

template <typename T>
Array<T>:: Array() : _array(NULL), _size(0) {std::cout << GREEN "Empty array" NC << std::endl;};

template <typename T>
Array<T>:: Array(unsigned int n): _array(new T[n]), _size(n) {};

template <typename T>
Array<T>:: Array(const Array &other): _array(new T[other._size]), _size(other._size)
{
	for (size_t i = 0; i < _size; i++) {
		this->_array[i] = other._array[i];}
}

template <typename T>
Array<T> &Array<T>:: operator=(const Array<T> &other)
{
	if (this == &other)
		return (*this);
	delete[] _array;
	_size = other._size;
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
	return (*this);
}

template <typename T>
Array<T>:: ~Array()
{
	delete [] _array;
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

template <typename T>
T &Array<T> :: operator[](const int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(_size))
		throw (OutOfBoundsException());
	return(_array[idx]);
}

template < typename T >
std::ostream& operator<< (std::ostream& out, const Array<T>& arr)
{
	for (size_t i =  0; i < arr.size(); i++)
		out << arr[i] << " ";
	return out;
}