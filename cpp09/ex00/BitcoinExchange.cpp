/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:40:56 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 11:05:41 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange:: BitcoinExchange() {}

BitcoinExchange:: BitcoinExchange(const BitcoinExchange &other) {
	_dataBase = other._dataBase; }

BitcoinExchange &BitcoinExchange:: operator=(const BitcoinExchange &other) {
	_dataBase = other._dataBase;
	return (*this);
}

BitcoinExchange:: ~BitcoinExchange() {}

float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
	if (this->_dataBase.count(date) > 0)
		return this->_dataBase.at(date);
	return (--this->_dataBase.lower_bound(date))->second;
}

bool BitcoinExchange:: isValidYear(const std::string year)
{
	if (year.length() != 4)
		return (false);
	int intYear = atoi(year.c_str());
	if (intYear < 2009 || intYear > 2022)
		return (false);
	return (true);
}

bool BitcoinExchange:: isValidMonth(const std::string month)
{
	if(month.length() > 2)
		return (false);
	int intMonth = atoi(month.c_str());
	if (intMonth < 1 || intMonth > 12)
		return (false);
	return (true);
}

bool BitcoinExchange:: isValidDay(const std::string day, const std::string month)
{
	if (day.length() > 2)
		return (false);
	int intDay = atoi(day.c_str());
	int intMonth = atoi(month.c_str());
	if (intDay < 1 || intDay > 31)
		return (false);
	if (intMonth == 2 && intDay > 29)
		return (false);
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30)
		return (false);
	return (true);
}

bool BitcoinExchange:: checkFormatDate(const std::string &date)
{
	if (date.empty())
		return false;

 	size_t first_hyphen = date.find('-');
    size_t second_hyphen = date.find('-', first_hyphen + 1);

	if (first_hyphen == std::string::npos || second_hyphen == std::string::npos
	||  date.find_first_not_of("0123456789.-") != std::string::npos)
		return false;
	std::string year = date.substr(0, first_hyphen);
	std::string month = date.substr(first_hyphen + 1, second_hyphen - first_hyphen - 1);
	std::string day = date.substr(second_hyphen + 1);
	if (isValidYear(year) == false || isValidMonth(month) == false || isValidDay(day, month) == false)
		return (false);
	return (true);
}

bool BitcoinExchange:: checkFormatValue(std::string &valueStr)
{
	if (isEmptyLine(valueStr))
		return false;
	std::size_t found = valueStr.find_first_not_of("0123456789.");
	if (found!=std::string::npos)
		throw (std::runtime_error("Error: invalid value"));
	float value = strtof(valueStr.c_str(), NULL);
	if (value < 0 || value > 1000)
		throw (std::runtime_error("Error: too large value for " + valueStr));
	return (true);
}

void BitcoinExchange:: readInputFile(std::string filePath)
{
	std::string line;
	std::fstream file(filePath.c_str(), std::fstream::in);
	if (!file.is_open())
		throw std::runtime_error("Could't open file");

	if (!(std::getline(file, line)))
		throw (std::runtime_error("Error: empty file"));
	if (line != "date | value")
		throw (std::runtime_error(line + "incorrect header"));
	while (std::getline(file, line))
	{
		try
		{
			if (isEmptyLine(line))
				continue;
			size_t delim = line.find('|');
			if (delim == std::string::npos)
				throw ( std::runtime_error("Error: bad input => " + line) );
			std::string date = strtrim(line.substr(0, delim));
			std::string value = strtrim(line.substr(delim + 1));
			if (checkFormatDate(date) == false || checkFormatValue(value) == false)
				throw ( std::runtime_error("Error: bad input => " + line) );

			float rate = strtof(value.c_str(), NULL);

			std::cout << CYAN << date << " => " << value << " = " << std::fixed << std::setprecision(2) << rate * getRateFromDataBase(date) << NC << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n'; }
	}
	file.close();
	return ;
}

void BitcoinExchange:: readDataBase(std::ifstream &dataB)
{
	std::string line;
	size_t delim;
	
	if (!std::getline(dataB, line))
		throw (std::runtime_error("Error: empty database"));
	while (std::getline(dataB, line))
	{
		delim = line.find(',');
		std::string date = line.substr(0, delim);
		std::string rate = line.substr(delim + 1);
		this->_dataBase[date] = strtof(rate.c_str(), NULL);
	}
	dataB.close();
	return ;
}
