/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/19 21:31:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main() {
  {
    std::cout << "\n--> My tests <--" << std::endl;
    try {
      Bureaucrat a("Bred", 30);
      Form b(a.getName(), 50, a.getGrade());
      b.beSigned(a);
      a.signForm(b);

      std::cout << b << std::endl;

      a.decrement();
      std::cout << a << std::endl;

      a.increment();

      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  {
    try {
      Bureaucrat a("Marcelo", 6);
      Form b("Sale Form", 5, 150);
      try {
        std::cout << "--> Increment test <--" << std::endl;
        std::cout << "--> Start Form with Bureaucrat: <--" << std::endl;
        std::cout << a << std::endl;
        std::cout << "--> Increment grade of Bureaucrat: <--" << std::endl;
        a.increment();
        std::cout << a << std::endl;
        std::cout << "--> Be signed: <--" << std::endl;
        b.beSigned(a);
        std::cout << a << std::endl;
        std::cout << "--> Sign Form: <--" << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
        std::cout << "--> End Form with Bureaucrat: <--" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << "--> End decrement test <--" << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      try {
        std::cout << "--> Decrement test <--" << std::endl;
        std::cout << b << std::endl;
        a.decrement();
        std::cout << a << std::endl;
        b.beSigned(a);
        a.signForm(b);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      std::cout << a << std::endl;
      std::cout << "--> End decrement test <--" << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}
