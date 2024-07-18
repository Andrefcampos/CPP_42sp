/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/17 01:58:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define RST "\033[0m"

int main() {
  std::cout << std::endl;
  std::cout << RED << "Test increment a high grade." << RST << std::endl;
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
  std::cout << RED << "Test decrement a low grade." << RST << std::endl;
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
  std::cout << RED << "Now different grade" << RST << std::endl;
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
