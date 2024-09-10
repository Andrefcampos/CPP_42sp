/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 04:21:10 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/09 22:17:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &param) {
	*this = param;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &param) {
	if (this != &param) {
		_deque = param._deque;
		_vector = param._vector;
	}
	return (*this);
}

void	PmergeMe::setVector(std::vector<std::string> const &vector) {
	for (std::size_t i = 0; i < vector.size(); i++) {
		if (!validateNumbers(vector[i])) {
			throw std::runtime_error("is not a valide number.");
		}
		_vector.push_back(atoi(vector[i].c_str()));
	}
}

void	PmergeMe::setDeque(std::deque<std::string> const &deque) {
	for (std::size_t i = 0; i < deque.size(); i++) {
		if (!validateNumbers(deque[i])) {
			throw std::runtime_error("is not a valide number.");
		}
		_deque.push_back(atoi(deque[i].c_str()));
	}
}

template<typename Container>
void	PmergeMe::insertionSort(Container &container, int n) {
	for (int i = 1; i < n; i++) {
		int	key = container[i];
		int	j = i - 1;

		while (j >= 0 && container[j] > key) {
			container[j + 1] = container[j];
			j = j - 1;
		}
		container[j + 1] = key;
	}
}

template<typename Container>
void	PmergeMe::mergeSort(Container &container, int left, int mid, int right) {
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::vector<int>	tempLeft(n1), tempRight(n2);

	for (int i = 0; i < n1; ++i) {
		tempLeft[i] = container[left + i];
	}

	for (int j = 0; j < n2; ++j) {
		tempRight[j] = container[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (tempLeft[i] <= tempRight[j]) {
			container[k] = tempLeft[i];
			i++;
		} else {
			container[k] = tempRight[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		container[k++] = tempLeft[i++];
	}

	while (j < n2) {
		container[k++] = tempRight[j++];
	}
}

template<typename Container>
void	PmergeMe::fordJohnsonSort(Container &container, int left, int right) {
	if (right - left + 1 <= 5) {
		insertionSort(container, right + 1);
		return ;
	}

	int	mid = left + (right - left) / 2;

	fordJohnsonSort(container, left, mid);
	fordJohnsonSort(container, mid + 1, right);

	mergeSort(container, left, mid, right);
}

void	PmergeMe::printVector(void) const {
	std::cout << YELLOW "[" DFT;
	for (std::size_t i = 0; i < _vector.size(); i++) {
		std::cout << GRAY << _vector[i] << DFT;
		if (i != _vector.size() - 1) {
			std::cout << YELLOW ", " DFT;
		}
	}
	std::cout << YELLOW "]" DFT << std::endl;
}

void	PmergeMe::printDeque(void) const {
	std::cout << YELLOW "[" DFT;
	for (std::size_t i = 0; i < _deque.size(); i++) {
		std::cout << GRAY << _deque[i] << DFT;
		if (i != _deque.size() - 1) {
			std::cout << YELLOW ", " DFT;
		}
	}
	std::cout << YELLOW "]" DFT << std::endl;
}

bool	PmergeMe::validateNumbers(std::string const &input) const {
	for (std::size_t i = 0; i < input.size(); i++) {
		if (!std::isdigit(input[i])) {
			return (false);
		}
	}
	return (true);
}

void	PmergeMe::resolveSort(void) {	
	std::cout << BLUE "Before: " DFT;
	printVector();

	std::clock_t	timeVec = std::clock();

	fordJohnsonSort(_vector, 0, _vector.size() - 1);

	timeVec = (std::clock() - timeVec) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << GREEN "After: " DFT;
	printVector();

	std::cout << std::endl;

	std::cout << YELLOW "Time to process a range of " << _vector.size() \
	<< " elements with std::vector : " DFT GREEN << timeVec << " us" DFT \
	<< std::endl;

	std::clock_t timeDeq = std::clock();

	fordJohnsonSort(_deque, 0, _deque.size() - 1);

	timeDeq = (std::clock() - timeDeq) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << YELLOW "Time to process a range of " << _deque.size() \
	<< " elements with std::deque : " DFT BLUE << timeDeq << " us" DFT \
	<< std::endl;
}
