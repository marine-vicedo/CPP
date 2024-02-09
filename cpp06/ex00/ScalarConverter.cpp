/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:11:23 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/10 14:23:57 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


// Initialisation des attributs statiques de la classe ScalarConverter
char ScalarConverter::_c = '\0';
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0.0f;
double ScalarConverter::_d = 0.0;
std::string ScalarConverter::_str = "";
type ScalarConverter::_type;

// Le reste des méthodes de la classe ScalarConverter

ScalarConverter:: ScalarConverter()
{

}


ScalarConverter:: ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter:: operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		_c = other._c;
		_i = other._i;
		_f = other._f;
		_d = other._d;
		_type = other._type;
		_str = other._str;
	}
	return (*this);
}

ScalarConverter:: ~ScalarConverter()
{

}

bool ScalarConverter:: isChar()
{
	if (_str.length() == 1 && !isdigit(_str[0]) && isprint(_str[0]))
		return (true);
	return (false);
}

//penser a test avec INT MAX et INT MIN pour atoi
bool ScalarConverter:: isInt()
{
	if (atof(_str.c_str()) > 2147483647 || atof(_str.c_str()) < -2147483648)
		return (false);
	std::size_t found = _str.find_first_not_of("-+0123456789");
	if (found!=std::string::npos)
		return (false);
	return (true);
}

bool ScalarConverter:: isFloat()
{
	std::size_t found = _str.find_first_not_of("-+.0123456789f");
	if (found!=std::string::npos)////If no such characters are found, the function returns string::npos.
		return (false);
	size_t f = _str.find('f');
	if (f != std::string::npos && f == _str.length() - 1)
		return (true);
	return (false);
}

bool ScalarConverter:: isDouble()
{
	std::size_t found = _str.find_first_not_of("-+.0123456789");
	if (found!=std::string::npos)//If no such characters are found, the function returns string::npos.
		return (false);
	size_t pos = _str.find('.');
	if (pos != std::string::npos)
		return (true);
	return (false);
}

bool ScalarConverter:: isLitteral()
{
	if (_str.compare("-inff") == 0 || _str.compare("+inff") == 0 || _str.compare("nanf") == 0
		|| _str.compare("-inf") == 0 || _str.compare("+inf") == 0 || _str.compare("nan") == 0)
	{
		//std::cout << "litteral\n";
		return (true);
	}
	return (false);
}

void ScalarConverter:: setType(std::string str)
{
	_str = str;
	if (isChar() == true)
		_type = CHAR;
	else if (isInt() == true)
		_type = INT;
	else if (isFloat() == true)
		_type = FLOAT;
	else if (isDouble() == true)
		_type = DOUBLE;
	else if (isLitteral() == true)
		_type = LITTERAL;
	else
		_type = NOTFOUND;
}

void ScalarConverter:: convert(std::string const str)
{
	//switch en fonction du _type et diriger vers les convert
	switch (_type)
	{
		case CHAR:
			_c = str[0];//conversion implicite
			_i = static_cast<int>(_c);//conversion explicite de char en int
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;
		case INT:
			_i = atoi(str.c_str());
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;
		case FLOAT:
			_f = atof(str.c_str());
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break;
		case DOUBLE:
			_d = atof(str.c_str());
			_c = static_cast<char>(_d);
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
			break;
		case LITTERAL:
			break;
		case NOTFOUND:
			break;
	}
}

void ScalarConverter:: printChar()
{
	if (_type == LITTERAL || _type == NOTFOUND)
		std::cout << "impossible\n";
	else if (_i < 33 || _i > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << _c << std::endl;
}

void ScalarConverter:: printInt()
{
	if (_type == LITTERAL || _type == NOTFOUND)
		std::cout << "impossible\n";
	else
		std::cout << _i << std::endl;
}

void ScalarConverter:: printFloat()
{
	if (_type == LITTERAL)
	{
		if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
			std::cout << "nanf\n";
		else if (_str.compare("-inff") == 0 ||_str.compare("-inf") == 0)
			std::cout << "-inf\n";
		else if (_str.compare("+inff") == 0 || _str.compare("+inf") == 0)
			std::cout << "+inf\n";
	}
	else if (_type == NOTFOUND)
		std::cout << "impossible\n";
	else if (_f - _i == 0)//verifier le cast
		std::cout << _f << ".0f" << std::endl;
	else
		std::cout << _f << "f" << std::endl;
}

void ScalarConverter:: printDouble()
{
	if (_type == LITTERAL)
	{
		if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
			std::cout << "nan\n";
		else if (_str.compare("-inff") == 0 ||_str.compare("-inf") == 0)
			std::cout << "-inff\n";
		else if (_str.compare("+inff") == 0 || _str.compare("+inf") == 0)
			std::cout << "+inff\n";
	}
	else if (_type == NOTFOUND)
		std::cout << "impossible\n";
	else if (_d - _i == 0.0)//verifier le cast
			std::cout << _d << ".0" << std::endl;
	else
		std::cout << _d << std::endl;
}

void ScalarConverter:: printAll()
{
	std::cout << "char: "; ScalarConverter::printChar();
	std::cout << "int: ";  ScalarConverter::printInt();
	std::cout << "float: ";  ScalarConverter::printFloat();
	std::cout << "double: ";  ScalarConverter::printDouble();
}
