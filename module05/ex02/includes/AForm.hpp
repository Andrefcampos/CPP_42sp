/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:23:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:22:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class	Bureaucrat;

class	AForm {

private:
	AForm(void);

	const std::string	_name;
	bool				_sign;
	const int			_signGrade;
	const int			_grade;

public:
	virtual ~AForm(void);
	AForm(std::string const &name, const int &signGrade, const int &grade);
	AForm(AForm const &param);

	AForm &operator=(AForm const &param);

	const std::string	getName(void) const;
	bool				getSign(void) const;
	int					getSignGrade(void) const;
	int					getGrade(void) const;

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
