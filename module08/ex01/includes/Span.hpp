
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iterator>

class   Span {
    private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

    public:
        Span();
        ~Span();
        Span(unsigned int num);
        Span(Span const &param);
        Span    &operator=(Span const &param);

        void    addNumber(int number);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        template <typename Iterator> void addRange(Iterator begin, Iterator end) {
            if (std::distance(begin, end) > static_cast<int>(_maxSize)) {
                throw std::overflow_error("Not enough space in Span to add entire range");
            }
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif
