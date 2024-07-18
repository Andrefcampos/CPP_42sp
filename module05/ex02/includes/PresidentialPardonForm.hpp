/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 04:56:44 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:22:21 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

private:
	PresidentialPardonForm(void);

	std::string	_target;

public:
	~PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &param);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &param);

	void	execute(Bureaucrat const &executor) const;
};

#endif
