/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:21:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:10:27 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
  {
    cout << "\nSubject test\n" << endl;

    const Animal *j = new Dog();
    const Animal *i = new Cat();
    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    delete j; // should not create a leak
    delete i;
  }
  std::cout << "\nMy tests\n" << std::endl;
  {
#define NBR_ANIMALS 4

    const Animal *i = new Dog();
    cout << endl;

    const Animal *j = new Cat();
    cout << endl;

    cout << "------------------- ZOO -------------------" << endl;
    const Animal *zoo[NBR_ANIMALS];

    cout << "------------------- DOGS -------------------" << endl;
    for (size_t i = 0; i < 2; i += 1) {
      zoo[i] = new Dog();
      cout << endl;
    }

    cout << "------------------- CATS -------------------" << endl;
    for (size_t i = 2; i < 4; i += 1) {
      zoo[i] = new Cat();
      cout << endl;
    }

    cout << "---------------- DELETE ZOO ---------------" << endl;
    for (size_t i = 0; i < NBR_ANIMALS; i += 1) {
      delete zoo[i];
    }
    cout << "--------------- ZOO DELETED ---------------" << endl;
    cout << endl;

    delete i;
    delete j;
  }
  return 0;
}
