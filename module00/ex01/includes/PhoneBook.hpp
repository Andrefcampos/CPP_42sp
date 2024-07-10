/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:09:42 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/03 03:59:44 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		size_t	_index;
		size_t	_max;
		Contact	_contacts[8];
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	setContact(void);
		void	searchContact(void);
};

#endif // !PHONEBOOK_HPP
