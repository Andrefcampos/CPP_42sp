/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 17:55:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  std::cout << std::endl;
  std::cout << "Test increment a high grade." << std::endl;
  {
    try {
      Bureaucrat john("High Grade Bure", 1);
      std::cout << john << std::endl;

      john.increment();
      std::cout << john << std::endl;

      john.decrement();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "Test decrement a low grade." << std::endl;
  {
    try {
      Bureaucrat john("Low Grade Bure", 150);
      std::cout << john << std::endl;

      john.decrement();
      std::cout << john << std::endl;

      john.increment();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "Now different grade" << std::endl;
  {
    try {
      Bureaucrat john("Mid Grade", 75);
      std::cout << john << std::endl;

      john.increment();
      std::cout << john << std::endl;

      john.decrement();
      std::cout << john << std::endl;

      while (john.getGrade() > 42)
        john.increment();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }

  return 0;
}
