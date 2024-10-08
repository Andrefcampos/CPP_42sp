/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:51:03 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 03:05:57 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class	Form;

class	Bureaucrat {

private:
	Bureaucrat(void);

	const std::string	_name;
	int					_grade;

public:
	~Bureaucrat(void);
	Bureaucrat(std::string const &name, int const &grade);
	Bureaucrat(Bureaucrat const &param);

	Bureaucrat	&operator=(Bureaucrat const &param);

	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int const &grade);

	void				increment(void);
	void				decrement(void);

	void				signForm(Form &param);

	class	GradeTooHighException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &oS, Bureaucrat const &param);

#endif
