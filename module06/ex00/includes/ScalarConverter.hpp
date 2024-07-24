
#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <exception>
# include <string>

# define BLUE_GREEN	"\033[32;44m"
# define MAG_YE		"\033[33;45m"
# define RED     	"\033[1;31m"
# define GREEN   	"\033[1;32m"
# define YELLOW 	"\033[1;33m"
# define BLUE    	"\033[1;34m"
# define MAGENTA    "\033[1;35m"
# define CYAN    	"\033[1;36m"
# define WHITE    	"\033[1;37m"
# define ORANGE		"\033[0;38;5;166m"
# define GRAY		"\033[38;5;244m"
# define DFT   		"\033[0m"

class	ScalarConverter {

private:
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(ScalarConverter const &param);
	ScalarConverter	&operator=(ScalarConverter const &param);

public:
	static void	convert(std::string const &str);

	class	InvalidStringException : public std::exception {
		virtual const char *what() const throw();
	};
};

enum	e_types {
	INVALID = -1,
	CHARNOTDISP = 1,
	CHARDISP,
	VALIDINT,
	VALIDFLOAT,
	VALIDDOUBLE,
	INFNEG,
	INFPOS,
	NAN
};

int		checkChar(std::string const &str);
bool	checkInt(std::string const &str);
bool	checkFloat(std::string const &str);
bool	checkDouble(std::string const &str);
bool	checkInfPos(std::string const &str);
bool	checkInfNeg(std::string const &str);
bool	checkNaN(std::string const &str);

void			displayChar(std::string const &str);
void			displayInt(std::string const &str);
void			displayFloat(std::string const &str);
void			displayDouble(std::string const &str);
void			displayInfNeg(std::string const &str);
void			displayInfPos(std::string const &str);
void			displayNaN(std::string const &str);

e_types			getType(std::string const &str);

unsigned int	decimalPrecision(std::string const &str);

void			printConvertString(std::string const &str, e_types type);

#endif
