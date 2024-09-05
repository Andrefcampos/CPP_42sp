/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:05:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/25 19:05:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
# include <stdexcept>

Span::Span(void) : _maxSize(0) {}

Span::~Span(void) {}

Span::Span(unsigned int num) : _maxSize(num) {}

Span::Span(Span const &param) {
	*this = param;
}

Span	&Span::operator=(Span const &param) {
	if (this != &param) {
		_numbers = param._numbers;
		_maxSize = param._maxSize;
	}
	return (*this);
}

void	Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
		throw std::out_of_range("Span is already full");
    }
	_numbers.push_back(number);
}

void	Span::addManyNumbers(void) {
	srand(time(0));

	while (_numbers.size() < _maxSize) {
		addNumber(rand() % (_maxSize * 10000));
	}
}

int	Span::shortestSpan(void) {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; i++) {
		int span = sorted[i + 1] - sorted[i];
        if (span < shortest) {
			shortest = span;
        }
    }
    return (std::abs(shortest));
}

int	Span::longestSpan(void) {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return (std::abs(max - min));
}
