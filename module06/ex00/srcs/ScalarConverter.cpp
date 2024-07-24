
#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <limits>

#define println(x) std::cout << x

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &param) {
	*this = param;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &param) {
	if (this != &param) {
		*this = param;
	}
	return (*this);
}

const char *ScalarConverter::InvalidStringException::what() const throw() {
	return (RED "string cannot be converted to a scalar type" DFT);
}

void	ScalarConverter::convert(const std::string &str) {
	if (getType(str) == INVALID) {
		throw (ScalarConverter::InvalidStringException());
	}
    printConvertString(str, getType(str));
}

unsigned int	decimalPrecision(std::string const &str) {
	unsigned int	decimal;
	
	if (str.find('.') == std::string::npos) {
		decimal = 1;
	} else {
		decimal = str.length() - str.find('.') - 1;
	}
	return (decimal);
}

int	checkChar(std::string const &str) {
	if (str.length() != 1) {
		return (0);
	}
	if (std::isdigit(str[0])) {
		return (0);
	} 
	if (std::isprint(str[0])) {
		return (1);
	}
	return (-1);
}

bool	checkInt(std::string const &str) {
	char	*lastChar;
	long	num = std::strtol(str.c_str(), &lastChar, 10);

	if (*lastChar != '\0') {
		return (false);
	} else if (num < std::numeric_limits<int>::min() \
		|| num > std::numeric_limits<int>::max()) {
		return (false);
	} else {
		return (true);
	}
}

bool	checkFloat(std::string const &str) {
	char	*lastChar;
	float	num = std::strtof(str.c_str(), &lastChar);

	if (*lastChar != 'f' || *(lastChar + 1) != '\0') {
		return (false);
	} else if (num == std::numeric_limits<float>::infinity() \
		|| num  == -std::numeric_limits<float>::infinity()) {
		return (false);
	} else if (str == "nanf") {
		return (false);
	} else {
		return (true);
	}
}

bool	checkDouble(std::string const &str) {

	if (str.find(".") == std::string::npos) {
		return (false);
	}
	char	*lastChar;
	double	num = std::strtod(str.c_str(), &lastChar);
	if (num == std::numeric_limits<double>::infinity() \
		|| (num * -1) == std::numeric_limits<double>::infinity() \
		|| num == std::numeric_limits<double>::quiet_NaN()) {
		return (false);
	} else if (*lastChar != '\0') {
		return (false);
	} else {
		return (true);
	}
}

bool	checkInfPos(std::string const &str) {
	std::string	infinity[4] = {"inf", "inff", "+inf", "+inff"};
	
	for (int i = 0; i < 4; i++) {
		if (str == infinity[i]) {
			return (true);
		}
	}
	return (false);
}

bool	checkInfNeg(std::string const &str) {
	std::string	infinity[2] = {"-inf", "-inff"};
	
	for (int i = 0; i < 2; i++) {
		if (str == infinity[i]) {
			return (true);
		}
	}
	return (false);
}

bool	checkNaN(std::string const &str) {
	std::string	infinity[2] = {"nan", "nanf"};
	
	for (int i = 0; i < 2; i++) {
		if (str == infinity[i]) {
			return (true);
		}
	}
	return (false);
}

e_types	getType(std::string const &str) {
	bool	(*f[6])(std::string const &) = {&checkInt, &checkFloat, \
		&checkDouble,  &checkInfNeg, \
		&checkInfPos, &checkNaN};

	if (checkChar(str) == -1) {
		return (CHARNOTDISP);
	} 
	if (checkChar(str) == 1) {
		return (CHARDISP);
	}
	for (int i = 0; i < 6; i++) {
		if (f[i](str) == true) {
			return ((e_types)(i + 3));
		}
	}
	return (INVALID);
}

void	displayChar(std::string const &str) {
	char	c = str[0];
	long	num = static_cast<int>(c);
	float	numf = static_cast<float>(c);
	double	numd = static_cast<double>(c);

	println(GREEN "char:\t" DFT BLUE);
	println(str[0]);
	println("\n"DFT);
	
	println(GREEN "int:\t" DFT YELLOW);
	println(static_cast<int>(num));
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(std::fixed << std::setprecision(decimalPrecision(str)) << numf);
	println("f\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(static_cast<double>(numd));
	println("\n"DFT);
}

void	displayInt(std::string const &str) {
	long	num = std::strtol(str.c_str(), NULL, 10);
	char	c = static_cast<char>(num);
	float	numf = static_cast<float>(num);
	double	numd = static_cast<double>(num);

	println(GREEN "char:\t" DFT YELLOW);
	if (num >= 0 && num <= 255) {
		if (std::isprint(c)) {
			println(c);
			println("\n"DFT);
		} else {
			println("Non displayble\n" DFT);
		}
	} else {
			println("impossible\n" DFT);
	}
	println(GREEN "int:\t" DFT BLUE);
	println(num);
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(std::fixed << std::setprecision(decimalPrecision(str)) << numf);
	println("f\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(numd);
	println("\n"DFT);
}

void	displayFloat(std::string const &str) {
	float	numf = std::strtof(str.c_str(), NULL);
	char	c = static_cast<char>(numf);
	long	num = static_cast<int>(numf);
	double	numd = static_cast<double>(numf);

	println(GREEN "char:\t" DFT YELLOW);
	if (num >= 0 && num <= 255) {
		if (std::isprint(c)) {
			println(c);
			println("\n"DFT);
		} else {
			println("Non displayble\n" DFT);
		}
	} else {
			println("impossible\n" DFT);
	}
	println(GREEN "int:\t" DFT YELLOW);
	println(num);
	println("\n"DFT);

	println(GREEN "float:\t" DFT BLUE);
	println(std::fixed << std::setprecision(decimalPrecision(str)) << numf);
	println("f\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(numd);
	println("\n"DFT);
}

void	displayDouble(std::string const &str) {
	double	numd = std::strtod(str.c_str(), NULL);
	char	c = static_cast<char>(numd);
	long	num = static_cast<int>(numd);
	float	numf = static_cast<float>(numd);

	println(GREEN "char:\t" DFT YELLOW);
	if (num >= 0 && num <= 255) {
		if (std::isprint(c)) {
			println(c);
			println("\n"DFT);
		} else {
			println("Non displayble\n" DFT);
		}
	} else {
			println("impossible\n" DFT);
	}
	println(GREEN "int:\t" DFT YELLOW);
	println(num);
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(std::fixed << std::setprecision(decimalPrecision(str)) << numf);
	println("f\n"DFT);

	println(GREEN "double:\t" DFT BLUE);
	println(numd);
	println("\n"DFT);

}

void	displayInfNeg(std::string const &str) {
	(void)str;
	float	numf = std::numeric_limits<float>::infinity() * -1;
	double	numd = std::numeric_limits<double>::infinity() * -1;

	println(GREEN "char:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "int:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(numf);
	println("f");
	println("\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(numd);
	println("\n"DFT);
}

void	displayInfPos(std::string const &str) {
	(void)str;
	float	numf = std::numeric_limits<float>::infinity();
	double	numd = std::numeric_limits<double>::infinity();

	println(GREEN "char:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "int:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(numf);
	println("f");
	println("\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(numd);
	println("\n"DFT);
}

void	displayNaN(std::string const &str) {
	(void)str;
	float	numf = std::numeric_limits<float>::quiet_NaN();
	double	numd = std::numeric_limits<double>::quiet_NaN();

	println(GREEN "char:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "int:\t" DFT YELLOW);
	println("impossible");
	println("\n"DFT);

	println(GREEN "float:\t" DFT YELLOW);
	println(numf);
	println("f");
	println("\n"DFT);

	println(GREEN "double:\t" DFT YELLOW);
	println(numd);
	println("\n"DFT);
}

void	printConvertString(std::string const &str, e_types type) {
	void	(*f[8])(std::string const &) = {&displayChar, &displayChar, \
		&displayInt, &displayFloat, &displayDouble, \
		&displayInfNeg, &displayInfPos, &displayNaN};

	for (int i = 1; (e_types)i <= NAN; i++) {
		if ((e_types)i == type) {
			f[i - 1](str);
			break ;
		}
	}
}
