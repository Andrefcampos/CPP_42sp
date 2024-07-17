/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:21:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:36:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define NBR_ANIMALS 4

using std::cout;
using std::endl;

int main(void) {
  {
    cout << "\nSubject test\n" << endl;

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    delete j; // should not create a leak
    delete i;
  }
  std::cout << "\nMy tests\n" << std::endl;
  {
	// AAnimal test = new AAnimal();

    const AAnimal *i = new Dog();
    cout << endl;

    const AAnimal *j = new Cat();
    cout << endl;

    cout << "--------------- CREATE ZOO ----------------" << endl;
    const AAnimal *zoo[NBR_ANIMALS];

    cout << "--------------- CREATE DOGS ---------------" << endl;
    for (size_t i = 0; i < 2; i += 1) {
      zoo[i] = new Dog();
      cout << endl;
    }

    cout << "--------------- CREATE CATS ---------------" << endl;
    for (size_t i = 2; i < 4; i += 1) {
      zoo[i] = new Cat();
      cout << endl;
    }

    cout << "---------------- DELETE ZOO ---------------" << endl;
    for (size_t i = 0; i < NBR_ANIMALS; i += 1) {
      delete zoo[i];
    }
    cout << "--------------- ZOO DELETED ---------------" << endl;

    delete i;
    delete j;
  }
  return 0;
}
