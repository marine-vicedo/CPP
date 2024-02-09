/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:14:30 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/08 18:38:48 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITTERAL,
	NOTFOUND,
};

class ScalarConverter
{
	private:
		ScalarConverter();
		
	public:
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		static char _c;
		static int _i;
		static float _f;
		static double _d;
		static type _type;
		static std::string _str;

		static void setType(std::string const str);

		static bool isChar();
		static bool isInt();
		static bool isFloat();
		static bool isDouble();
		static bool isLitteral();
		
		static void convert(std::string const str);
		
		static void printAll();
		static void printChar();
		static void printInt();
		static void printFloat();
		static void printDouble();
};

#endif