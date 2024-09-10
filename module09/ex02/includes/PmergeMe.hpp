/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 04:21:29 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/09 19:21:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# define BLUE_GREEN "\033[32;44m"
# define MAG_YE "\033[33;45m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define ORANGE "\033[0;38;5;166m"
# define GRAY "\033[38;5;244m"
# define DFT "\033[0m"

# include <deque>
# include <vector>
# include <string>

class	PmergeMe {
private:
	std::deque<int>	_deque;
	std::vector<int> _vector;

	template<typename Container>
	void	insertionSort(Container &container, int n);
	template<typename Container>
	void	mergeSort(Container &container, int left, int mid, int right);
	template<typename Container>
	void	fordJohnsonSort(Container &container, int left, int right);
	bool	validateNumbers(std::string const &input) const;

public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(PmergeMe const &param);
	
	PmergeMe	&operator=(PmergeMe const &param);

	void	resolveSort(void);
	void	printVector(void) const;
	void	printDeque(void) const;
	void	setVector(std::vector<std::string> const &vector);
	void	setDeque(std::deque<std::string> const &deque);
};

#endif
