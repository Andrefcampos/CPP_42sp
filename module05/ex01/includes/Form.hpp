/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:23:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 03:05:45 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class	Form {

private:
	Form(void);

	const std::string	_name;
	bool				_sign;
	const int			_signGrade;
	const int			_grade;

public:
	~Form(void);
	Form(std::string const &name, const int &signGrade, const int &grade);
	Form(Form const &param);

	Form &operator=(Form const &param);

	const std::string	getName(void) const;
	bool				getSign(void) const;
	int					getSignGrade(void) const;
	int					getGrade(void) const;

	void				beSigned(Bureaucrat &param);

	class	GradeTooHighException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &oS, Form const &param);

#endif
