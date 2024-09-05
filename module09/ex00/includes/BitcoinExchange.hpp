/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:24:51 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/05 03:18:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_COIN_EXCHANGE_HPP
# define BIT_COIN_EXCHANGE_HPP

# define BLUE_GREEN "\033[32;44m"
# define MAG_YE "\033[33;45m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define ORANGE "\033[0;38;5;166m"
# define GRAY "\033[38;5;244m"
# define DFT "\033[0m"

# include <map>
# include <string>

class	BitcoinExchange {

private:
	std::map<std::string, float>	_data;
	std::string						_file;

	BitcoinExchange(void);

	void	setData(void);
	bool	validateDate(std::string const &date) const;
	float	convertBitcoin(std::string const &date, float const &valueInput);
	void	printExchange(std::string const &input);
	bool	validateInput(std::string const &input) const;
	float	findValue(std::string const &key) const;
	void	printData(void) const;

public:
	~BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &param);
	BitcoinExchange(std::string const &file);

	BitcoinExchange	&operator=(BitcoinExchange const &param);

	void	printFile(std::string const &file);

};

#endif
