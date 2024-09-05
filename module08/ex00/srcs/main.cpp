/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:46:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/27 16:04:34 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

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
#define printerr std::cerr << e.what() << std::endl;

int main() {
  println(BLUE_GREEN "===== TEST WHIT VECTOR =====" DFT) << "\n";
  try {
    std::vector<int> vec;

    for (int i = 0; i < 5; i++) {
      vec.push_back((i + 1) * 10);
    }

    println(BLUE "Find number 30\n" DFT);
    println(YELLOW "Found: ") << easyfind(vec, 30) << DFT << std::endl;
    println(BLUE "Find number 42\n" DFT);
    println(RED "Find: ") << easyfind(vec, 42) << DFT << std::endl;

  } catch (const std::exception &e) {
    printerr
  }
  println(WHITE "\n" DFT);
  println(BLUE_GREEN "===== TEST WHIT DEQUE =====" DFT) << "\n";
  try {
    std::deque<int> deq;

    for (int i = 0; i < 5; i++) {
      deq.push_back((i + 1) * 10);
    }

    println(BLUE "Find number 50\n" DFT);
    println(YELLOW "Found: ") << easyfind(deq, 50) << DFT << std::endl;
    println(BLUE "Find number 31\n" DFT);
    println(RED "Find: ") << easyfind(deq, 31) << DFT << std::endl;

  } catch (const std::exception &e) {
    printerr
  }
  println(WHITE "\n" DFT);
  println(BLUE_GREEN "===== TEST WHIT LIST =====" DFT) << "\n";
  try {
    std::list<int> lst;

    for (int i = 0; i < 5; i++) {
      lst.push_back((i + 1) * 10);
    }

    println(BLUE "Find number 10\n" DFT);
    println(YELLOW "Found: ") << easyfind(lst, 10) << DFT << std::endl;
    println(BLUE "Find number 65\n" DFT);
    println(RED "Find: ") << easyfind(lst, 65) << DFT << std::endl;

  } catch (const std::exception &e) {
    printerr
  }
  println(WHITE "\n" DFT);
  return 0;
}
