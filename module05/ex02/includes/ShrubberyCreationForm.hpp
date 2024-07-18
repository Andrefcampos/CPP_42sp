/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:27:18 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:22:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
#include "Bureaucrat.hpp"


class	ShrubberyCreationForm : public AForm {

private:
	ShrubberyCreationForm(void);

	std::string	_target;

public:
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &param);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &param);

	void	execute(Bureaucrat const &executor) const;

	class FileWriteException : public std::exception {
    	public:
        	const char *what() const throw() {
			return "Failed writing to file.";
		}
    };

    class FailedToOpenException : public std::exception {
	    public:
    	    const char *what() const throw() {
        	    return "Failed opening file.";
	        }
	};
};

#endif
