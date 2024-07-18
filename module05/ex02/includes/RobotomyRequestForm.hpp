/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:01:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:22:28 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

private:
	RobotomyRequestForm(void);

	std::string	_target;

public:
	~RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &param);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &param);

	void	execute(Bureaucrat const &executor) const;
};

#endif
