/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:44:16 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/03 04:07:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
	private:
		std::string	_firstName, _lastName, _nickName, _phoneNumber, _darkstSecret;

	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(const std::string firstName);
		void		setLastName(const std::string lastName);
		void		setNickName(const std::string nickName);
		void		setPhoneNumber(const std::string phoneNumber);
		void		setDarkstSecret(const std::string darkstSecret);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkstSecret(void);

		void	display(void);
};

#endif //CONTACT_HPP
