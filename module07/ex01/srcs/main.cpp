/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:50:06 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/22 11:20:36 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
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

void increment(int &num) { num++; }

void printArrInt(int &x) {
  println(GREEN "Number: ");
  println(x) << "\n" DFT;
}

void printArrString(std::string &x) {
  println(GREEN "String: ");
  println(x) << "\n" DFT;
}

int main(void) {
  println(BLUE_GREEN "\n=====> START TESTS <======\n" DFT);
	{
		println(YELLOW "\n----> Tests with int <----\n" DFT);
		int arr[5] = {1, 2, 3, 4, 5};

		println(BLUE "\nOriginal array: \n\n" DFT);
		iter(arr, 5, printArrInt);

		println(BLUE "\nModified array: \n\n" DFT);
		iter(arr, 5, increment);
		iter(arr, 5, printArrInt);

	}
	{
		println(YELLOW "\n----> Tests with string <----\n" DFT);
		std::string arr[5] = {"car","bird", "cloud", "tree", "house"};
		println(BLUE "\nPrint array: \n\n" DFT);
		iter(arr, 5, printArrString);
	}

  println(BLUE_GREEN "\n=====> END TESTS <======\n" DFT);

  return 0;
}
