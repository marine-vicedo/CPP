/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:28:08 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/23 17:02:58 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

/*on utilise un template de classe avec 2 parametres :
T reprensente le type de donnees stockees
C represente le conteneur sous-jacent*/
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T, C>(other) {};
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other) {
				this->c = other.c; } //on copie le conteneur sous-jacent
			return (*this);
		};
		//~MutantStack();
		        
		typedef typename std::stack<T, C>::container_type::iterator					iterator;
		typedef typename std::stack<T, C>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T, C>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T, C>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		reverse_iterator rbegin() const { return this->c.rbegin(); }
		reverse_iterator rend() const { return this->c.rend(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif