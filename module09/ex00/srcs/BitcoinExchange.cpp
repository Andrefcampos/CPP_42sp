/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:14:56 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/05 03:52:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>

BitcoinExchange::BitcoinExchange(void) : _file(   "./data.csv") {
	setData();
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &param) {
	*this = param;
}

BitcoinExchange::BitcoinExchange(std::string const &file) {
	_file = file;
	setData();
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &param) {
	if (this != &param) {
		_data = param._data;
		_file = param._file;
	}
	return (*this);
}

bool	BitcoinExchange::validateDate(std::string const &date) const {

	int	year, moth, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &moth, &day) != 3) {
		return (false);
	}

	if (moth < 1 || moth > 12) {
		return (false);
	}

	if (year < 2009 || year > 2024) {
		return (false);
	}

	bool	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	int	daysInMoths[] = {31, ((isLeapYear) ? 29 : 28), 31, 30, \
		31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > daysInMoths[moth - 1]) {
		return (false);
	}

	return (true);
}

void	BitcoinExchange::setData(void) {

	if (std::strcmp(_file.c_str(), "./data.csv")) {
		throw std::runtime_error("not found data file: " + _file);
	}

	std::ifstream	dataFile(_file.c_str());

	if (!dataFile) {
		throw std::runtime_error("could not open file.");
	}

	std::string	firstLine;
	std::getline(dataFile, firstLine);

	if (strcmp(firstLine.c_str(),"date,exchange_rate")) {
		throw std::runtime_error("Wrong fields.");
	}

	std::string	line;

	while (std::getline(dataFile, line)) {
		if (line == firstLine) {
			continue ; 
		} else {
			std::size_t	commaPos = line.find(',');
			std::string	key = line.substr(0, commaPos);
			std::string	value = line.substr(commaPos + 1, std::string::npos);
			float	valuef = atof(value.c_str());
			_data[key] = valuef;
		}
	}
	dataFile.close();
}

void	BitcoinExchange::printData(void) const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); \
	it != _data.end(); ++it) {
            std::cout << "Data: " << it->first << ", Value: " << it->second \
			<< std::fixed << std::setprecision(2) << std::endl;
        }
    }

void	BitcoinExchange::printFile(std::string const &fileName) {
	std::ifstream	file(   fileName.c_str());

	if (!file) {
		throw std::runtime_error(RED "could not open file." DFT);
	}

	std::string line;
	std::string firstLine;
	getline(file, firstLine);

	if (strcmp(firstLine.c_str(), "date | value")) {
		throw std::runtime_error(RED "wrong field. \"date | value\"" DFT);
	}

	while (std::getline(file, line)) {
		if (line == firstLine) {
			continue;
		}
		try {
			printExchange(line);
		} catch (const std::exception &e) {
			std::cerr << RED "Error: " << e.what() << DFT << std::endl;
		}
		std::cout << std::endl;
	}
	file.close();
}

bool	BitcoinExchange::validateInput(std::string const &input) const {
	if (input.length() < 14) {
		return (false);
	}
	if (input[4] != '-' || input[7] != '-' || input[10] != ' ' || input[11] != '|' || input[12] != ' ') {
		return (false);
	}
	int	year, moth, day;
	float	value;
	char	extra;
	if (sscanf(input.c_str(), "%d-%d-%d | %f%c", &year, &moth, &day, &value, &extra) != 4) {
		return (false);
	}

	std::size_t	space = input.find(' ');
	std::string	date = input.substr(0, space);
	if (validateDate(date) == false) {
		return (false);
	}
	return (true);
}

float	BitcoinExchange::findValue(std::string const &key) const {
	std::map<std::string, float>::const_iterator	it;

	it = _data.lower_bound(key);

	if (key != it->first) {
		--it;
	}
	std::cout << BLUE "Date ref: " DFT YELLOW << it->first \
		<< DFT BLUE " | Value 1BTC: " DFT YELLOW << it->second << DFT << std::endl;
	return (it->second);
}

float	BitcoinExchange::convertBitcoin(std::string const &date, \
										float const &valueInput) {
	if (valueInput > 1000) {
		std::cerr << ORANGE << date << " | " << valueInput << std::fixed \
		<< std::setprecision(2) << DFT << std::endl;
		throw std::runtime_error(RED "too large a number." DFT);
	} else if (valueInput < 0) {
		std::cerr << ORANGE << date << " | " << valueInput << std::fixed \
		<< std::setprecision(2) << DFT << std::endl;
		throw std::runtime_error(RED "not a positive number." DFT);
	}
	
	if (valueInput == 0) {
		return (valueInput);
	}

	float	value = findValue(date);
	float	convertedValue = value * valueInput; 

	return (convertedValue);
}

void	BitcoinExchange::printExchange(std::string const &input) {

	if (validateInput(input) == false) {
		std::string	err = RED "bad input => " + input + DFT;
		throw std::runtime_error(      err.c_str() );
	}
	std::size_t	space = input.find(' ');
	std::string	date = input.substr(0, space);
	std::string	valueInput = input.substr(input.find('|') + 2, std::string::npos);

	float	valueInputf = atof(valueInput.c_str());
	float	convertedValue = convertBitcoin(date, valueInputf);

	std::cout << YELLOW << date << DFT;
	std::cout << BLUE " => " DFT;
	std::cout << YELLOW << valueInput << DFT;
	std::cout << BLUE " = " DFT;
	std::cout << GREEN << convertedValue << std::fixed << std::setprecision(2);
	std::cout << DFT << std::endl;
}
