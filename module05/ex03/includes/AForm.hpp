/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:23:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 04:41:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

#define BLUE_GREEN	"\033[32;44m"
#define MAG_YE		"\033[33;45m"
#define RED     	"\033[1;31m"
#define GREEN   	"\033[1;32m"
#define YELLOW 		"\033[1;33m"
#define BLUE    	"\033[1;34m"
#define MAGENTA    	"\033[1;35m"
#define CYAN    	"\033[1;36m"
#define WHITE    	"\033[1;37m"
#define ORANGE		"\033[0;38;5;166m"
#define GRAY		"\033[38;5;244m"
#define DFT   		"\033[0m"

class	Bureaucrat;

class	AForm {

private:
	AForm(void);

	const std::string	_name;
	bool				_sign;
	const int			_gradeToSign;
	const int			_gradeToExec;

public:
	virtual ~AForm(void);
	AForm(std::string const &name, const int &gradeToSign, const int &gradeToExec);
	AForm(AForm const &param);

	AForm &operator=(AForm const &param);

	const std::string	getName(void) const;
	bool				getSign(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;

	void				beSigned(Bureaucrat &param);

	virtual void		execute(Bureaucrat const &executor) const = 0;

	class	GradeTooHighException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {

		public:
    		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &oS, AForm const &param);

#endif
