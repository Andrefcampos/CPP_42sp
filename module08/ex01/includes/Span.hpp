/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:05:29 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/25 19:04:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class   Span {
    private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

    public:
        Span();
        ~Span();
        Span(unsigned int num);
        Span(Span const &param);

        Span	&operator=(Span const &param);

        void	addNumber(int number);
        int		shortestSpan(void);
        int		longestSpan(void);
		void	addManyNumbers(void);
};

#endif
