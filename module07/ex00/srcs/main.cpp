/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:49:41 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/22 10:59:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

#define BLUE_GREEN "\033[32;44m"
#define MAG_YE "\033[33;45m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define ORANGE "\033[0;38;5;166m"
#define GRAY "\033[38;5;244m"
#define DFT "\033[0m"

#define println(x) std::cout << x

int main(void) {
  int a = 2;
  int b = 3;

  println(BLUE_GREEN "\n=====> START TESTS <======\n" DFT);
  println(BLUE "\n----> Test with int <----\n" DFT);
  println(BLUE "Original:\n" DFT);
  std::cout << YELLOW "a = " << a << ", b = " << b << DFT << std::endl;
  swap(a, b);
  println(BLUE "Modified (swap):\n" DFT);
  std::cout << YELLOW "a = " << a << ", b = " << b << DFT << std::endl;
  std::cout << GREEN "min( a, b ) = " << min(a, b) << DFT << std::endl;
  std::cout << GREEN "max( a, b ) = " << max(a, b) << DFT << std::endl;

  println(BLUE "\n----> Test with string <----\n" DFT);
  std::string c = "channel1";
  std::string d = "channel2";
  println(BLUE "Original:\n" DFT);
  std::cout << YELLOW "c = " << c << ", d = " << d << DFT << std::endl;
  swap(c, d);
  println(BLUE "Modified (swap):\n" DFT);
  std::cout << YELLOW "c = " << c << ", d = " << d << DFT << std::endl;
  std::cout << GREEN "min( c, d ) = " << min(c, d) << DFT << std::endl;
  std::cout << GREEN "max( c, d ) = " << max(c, d) << DFT << std::endl;
  println(BLUE_GREEN "\n=====> END TESTS <======\n" DFT);
  return 0;
}
