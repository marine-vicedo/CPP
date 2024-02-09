/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/22 14:18:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

#include <vector>
#include <list>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
		std::vector<int> _range;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		std::vector<int> const &	getRange(void) const;
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		
		/*----------------------------------*/
		class Full : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		/*----------------------------------*/
		template <typename T>
		void addRange(typename T::iterator &begin, typename T::iterator &end)
		{
			unsigned int distance = std::distance(begin, end);//size de la plage a ajouter
			
			if (distance > this->_maxSize - this->_range.size())
				throw(Span::Full());
			if (distance != 0)
				_range.insert(_range.end(), begin, end);
			return;
		}
};

std::ostream &	operator<<(std::ostream &os, Span &obj);

#endif