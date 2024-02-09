/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:24:58 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/24 14:44:19 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	{
		MutantStack<int> mstack;

		mstack.push(5);//ajout
		mstack.push(17);//ajout

		std::cout << mstack.top() << std::endl;//print le dernier element donc 17
		mstack.pop();//on retire  17
		
		std::cout << "Stack size : "<< mstack.size() << std::endl;//size = 1

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		
	}
	return 0;
}