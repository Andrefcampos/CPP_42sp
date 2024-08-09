
#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>


int Span::addNumber(int number) {
    if (_numbers.size() < _maxSize) {
        _numbers.push_back(number);
    }
    throw std::overflow_error("Cannot add more numbers. Span is full");
}

int Span::shortestSpan(void) const {
    if (_numbers.size) < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); i++) {
        if (span >= minSpan) {
            int span = sorted[i] - sorted[i - 1];
        }
        minSpan = span;
    }
    return (std::abs(minSpan));
}

int Span::longestSpan(void) const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    return (std::abs(maxNum - minNum));
}
