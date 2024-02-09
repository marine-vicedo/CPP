/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:06:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 11:06:18 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <exception>
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>

#define CYAN "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define NC "\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dataBase;

		bool checkFormatDate(const std::string &date);
		bool checkFormatValue(std::string &valueStr);

		bool isValidYear(const std::string year);
		bool isValidMonth(const std::string month);
		bool isValidDay(const std::string day, const std::string month);

		float getRateFromDataBase(const std::string& date);
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void readDataBase(std::ifstream &dataB);
		void readInputFile(std::string filePath);

};
std::string strtrim(std::string src);
bool isEmptyLine(std::string &line);

#endif