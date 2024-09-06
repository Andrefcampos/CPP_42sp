/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:10:16 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/06 04:03:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

# include <stack>
# include <string>

class	RPN {

private:
	
	std::stack<int>	_stack;
	std::string		_expression;

	void	resolveRPN(void);
	RPN(void);
	RPN	&operator=(RPN const &param);
	RPN(RPN const &param);

public:
	RPN(std::string const &expression);
	~RPN(void);

	void	printRPN(void);
};

#endif
