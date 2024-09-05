/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:45:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/27 15:57:57 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
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
#define printerr std::cerr << RED "Exception: " << e.what() << DFT << std::endl;

void mandatoryTest(void) {

  Span sp = Span(5);

  try {
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    println(GREEN "Container = [6, 3, 17, 9, 11]\n" DFT);

    println(YELLOW "Shortest span = ");
    println(sp.shortestSpan()) << '\n' << DFT;

    println(YELLOW "Longest span = ");
    println(sp.longestSpan()) << '\n' << DFT;

  } catch (const std::exception &e) {
    printerr
  }
}

void testManyNumbers(int range) {

  Span sp = Span(range);

  println(CYAN "-----> CONTAINER WITH ") << range;
  println(" NUMBERS <-----\n" DFT);

  try {
    sp.addManyNumbers();
    println(YELLOW "Shortest span = ");
    println(sp.shortestSpan()) << '\n' << DFT;
    println(YELLOW "Longest span = ");
    println(sp.longestSpan()) << '\n' << DFT;
  } catch (std::exception &e) {
    printerr
  }
}

void testAddError(int range, int num) {

  Span sp = Span(range);

  println(CYAN "-----> CONTAINER WITH ") << range;
  println(" NUMBERS <-----\n" DFT);

  num *= -1;

  try {
    sp.addManyNumbers();
    println(YELLOW "Shortest span = ");
    println(sp.shortestSpan()) << '\n' << DFT;
    println(YELLOW "Longest span = ");
    println(sp.longestSpan()) << '\n' << DFT;
    println('\n');
    println(GREEN "--> ADD ") << num << " IN FULL CONTAINER <--\n" DFT;
    sp.addNumber(-2);
  } catch (std::exception &e) {
    printerr
  }
}

void testErrorContainerSizeOne(void) {
  Span sp = Span(1);

  println(CYAN "-----> CONTAINER WITH 1");
  println(" NUMBERS <-----\n" DFT);
  try {
    sp.addManyNumbers();
    println(YELLOW "Shortest span = ");
    println(sp.shortestSpan()) << '\n' << DFT;
  } catch (std::exception &e) {
    printerr
  }
  println('\n');
  try {
    println(YELLOW "Longest span = ");
    println(sp.longestSpan()) << '\n' << DFT;
  } catch (std::exception &e) {
    printerr
  }
}

int main(void) {
  println(BLUE "\n===== MADATORY TEST: =====\n\n" DFT);
  mandatoryTest();
  println(BLUE "\n===== END TEST: ====\n" DFT);

  println(MAGENTA "\n===== MANY NUMBERS TEST: ====\n\n" DFT);
  testManyNumbers(10);
  println("\n");
  testManyNumbers(10000);
  println(MAGENTA "\n===== END TEST: ====\n" DFT);

  println(RED "\n===== TEST ADD ERROR: ====\n\n" DFT);
  testAddError(4, 10);
  println(RED "\n===== END TEST: ====\n" DFT);

  println(RED "\n===== TEST ERROR CONTAINER SIZE 1: ====\n\n" DFT);
  testErrorContainerSizeOne();
  println(RED "\n===== END TEST: ====\n" DFT);
  return 0;
}
