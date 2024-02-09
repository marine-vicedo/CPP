/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:04:46 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/22 14:14:39 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _range(), _maxSize(0)
{
    return;
}

Span::Span(unsigned int N): _range(), _maxSize(N)
{
    return;
}

Span::Span(const Span &other): _range(other._range), _maxSize(other._maxSize)
{
    return;
}

Span &Span:: operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _range.clear();
        _range.insert(_range.end(), other._range.begin(), other._range.end());
    }
    return (*this);
}

Span::~Span(void)
{
	return ;
}

std::vector<int> const &	Span::getRange(void) const
{
	return (this->_range);
}

void Span:: addNumber(int number)
{
    if (_range.size() == _maxSize)
    	throw(Span::Full());
    _range.push_back(number);
    return ;
}

unsigned int Span:: shortestSpan() const
{
	if (_range.size() < 2)
		throw std::logic_error(RED "Not enough numbers to find shortest span" NC);

	std::vector<int> tmp(_range);//on declare un tmp pour le tri
	std::sort(tmp.begin(), tmp.end());
	
	int shortest = std::numeric_limits<int>::max();//int max
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span:: longestSpan() const
{
	if (_range.size() < 2)
		throw std::logic_error(RED "Not enough numbers to find longest span" NC);

	unsigned int min = *std::min_element(_range.begin(), _range.end());
	unsigned int max = *std::max_element(_range.begin(), _range.end());
	return (max - min);
}

const char *	Span::Full::what() const throw()
{
	return (RED "Too many numbers in range." NC);
}

std::ostream &	operator<<(std::ostream &os, Span &obj)
{
    for (std::vector<int>::const_iterator it = obj.getRange().begin();
			it != obj.getRange().end(); ++it)
		std::cout << "[" << *it << "] ";
    return (os);
}