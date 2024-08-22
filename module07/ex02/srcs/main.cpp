/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/22 11:22:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <cstdlib>
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

#define MAX_VAL 750

void increment(int &num) { num++; }

void testInt(void) {

  println(BLUE "\n---> Start tests with Array int <---- \n" DFT);

  Array<int> vec(10);

  println(YELLOW "\nBuild Array int \n\n" DFT);

  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    vec[i] = i;
  }

  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    println(GREEN "Array num: ");
    println(vec[i]) << DFT << std::endl;
  }

  println(YELLOW "\nSum Array: \n\n" DFT);

  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    increment(vec[i]);
    println(GREEN "Sum Array: ");
    println(vec[i]) << DFT "\n";
  }

  println(RED "\nErrors index Array: \n" DFT);
  println(YELLOW "\nNegative index: \n" DFT);
  try {
    println(vec[-1]) << '\n';
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << DFT << std::endl;
  }

  println(YELLOW "\nExactly Array index: \n" DFT);
  try {
    int index = static_cast<int>(vec.size());
    println(vec[index]) << '\n';
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << DFT << std::endl;
  }

  println(BLUE "\nEnd tests with Array int \n" DFT);
}

void testString(void) {

  println(BLUE "\n----> Start tests with Array of strings <---- \n" DFT);

  Array<std::string> vec(5);
  std::string list[5] = {"car", "cat", "bird", "dog", "house"};

  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    vec[i] = list[i];
  }

  println(YELLOW "\nBuild Array string \n\n" DFT);
  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    println(GREEN "Array str: ");
    println(vec[i]) << DFT << std::endl;
  }

  println(RED "\nErrors index Array: \n" DFT);
  println(YELLOW "\nNegative index: \n" DFT);
  try {
    println(vec[-10]) << '\n';
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << DFT << std::endl;
  }

  println(YELLOW "\nExactly Array index: \n" DFT);
  try {
    int index = static_cast<int>(vec.size());
    println(vec[index + 6]) << '\n';
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << DFT << std::endl;
  }

  println(BLUE "\nEnd tests with Array of strings \n" DFT);
}

void nextStep(void) {
  std::string buf;

  println(GRAY "PRESS ENTER" DFT);
  std::getline(std::cin, buf);
  system("clear");
}

int main(void) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];

  println(BLUE_GREEN "\n=====> TESTS SUBJECT <===== \n" DFT);

  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    // std::cout << "numero: " << numbers[i] << std::endl;
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }

  delete[] mirror; //

  std::string buf;

  println(BLUE_GREEN "\n=====> MY TESTS <===== \n" DFT);
  testInt();
  nextStep();
  testString();
  nextStep();

  println(BLUE_GREEN "\n\n\n\n=====> END TESTS <====== \n\n\n\n\n" DFT);

  return 0;
}
