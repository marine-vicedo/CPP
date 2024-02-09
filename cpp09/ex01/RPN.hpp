/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:27:41 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 11:17:48 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <cstdlib>
#include <limits>

class RPN
{
	private:
		std::string _input;
		std::stack<int> _stack;
		
		RPN();
		void evalRpnExpression();
		bool isOperator(char &elem) const;
		void evaluateOperation(char &op);

	public:
		RPN (std::string input);
		RPN (const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN ();

		void getResult();




};

#endif