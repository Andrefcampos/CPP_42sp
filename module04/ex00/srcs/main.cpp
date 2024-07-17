/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:21:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:14:54 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
  {
    cout << "\nSubjects tests:\n" << endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
  }
  {
    cout << "\nMy tests:\n" << endl;
    cout << "---------- Animal & Cat/Dog ----------" << endl;
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    const Animal *meta_animal = new Animal();

    cout << dog->getType() << "-> ";
    dog->makeSound();

    cout << cat->getType() << "-> ";
    cat->makeSound();

    cout << endl;

    meta_animal->makeSound();

    cout << endl;

    cout << "---------- WrongAnimal & WrongCat ----------" << endl;

    const WrongAnimal *wrong_cat = new WrongCat();
    const WrongAnimal *meta_wrong_animal = new WrongAnimal();

    cout << endl;

    cout << wrong_cat->getType() << "-> ";
    wrong_cat->makeSound();

    meta_wrong_animal->makeSound();

    cout << endl;

    delete dog;
    delete cat;
    delete meta_animal;
    delete wrong_cat;
    delete meta_wrong_animal;
  }
  return 0;
}
