/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:42:47 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/25 00:22:47 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:
	MutantStack(void) {}
	~MutantStack(void) {}
	MutantStack(MutantStack const &param) : std::stack<T>(param) {}

	MutantStack	&operator=(MutantStack const &param) {
		if (this != &param) {
			std::stack<T>::operator=(param);
		}
		return (*this);
	}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator	begin(void) {
		return (this->c.begin());
	}

	iterator	end(void) {
		return (this->c.end());
	}

	const_iterator	begin(void) const {
		return (this->c.begin());
	}

	const_iterator	end(void) const {
		return (this->c.end());
	}
};

#endif
