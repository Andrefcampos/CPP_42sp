/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 04:55:26 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

#define printt(x) std::cout << x;

void testShrubbery(void) {
  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test ShrubberyCreationForm " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(BLUE " Shrubbery success execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *a = new ShrubberyCreationForm("Home");
  Bureaucrat b("Mick", 129);

  std::cout << b << std::endl;

  b.signForm(*a);
  b.executeForm(*a);
  printt("\n");

  std::cout << *a << std::endl;

  delete a;

  printt(RED "x->" DFT);
  printt(YELLOW " Shrubbery failed execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *c = new ShrubberyCreationForm("Build");
  Bureaucrat d("Jay", 138);

  std::cout << d << std::endl;

  d.signForm(*c);
  d.executeForm(*c);
  printt("\n");

  std::cout << *c << std::endl;

  delete c;

  printt(BLUE "-->" DFT);
  printt(GREEN " End test ShrubberyCreationForm " DFT);
  printt(BLUE "<--\n" DFT);
}

void testRobotomyRequest(void) {
  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test RobotomyRequestForm " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(BLUE " RobotomyRequest success execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *a = new RobotomyRequestForm("Auto");
  Bureaucrat b("Xavier", 43);

  std::cout << b << std::endl;

  b.signForm(*a);
  b.executeForm(*a);
  printt("\n");

  std::cout << *a << std::endl;

  delete a;

  printt(RED "x->" DFT);
  printt(YELLOW " RobotomyRequest failed execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *c = new RobotomyRequestForm("Movel");
  Bureaucrat d("Ramires", 47);

  std::cout << d << std::endl;

  d.signForm(*c);
  d.executeForm(*c);
  printt("\n");

  std::cout << *c << std::endl;

  delete c;

  printt(BLUE "-->" DFT);
  printt(GREEN " End test RobotomyRequestForm " DFT);
  printt(BLUE "<--\n" DFT);
}

void testPresidentialPardon(void) {
  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test PresidentialPardonForm " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(YELLOW " Fail grade to sign and execute form " DFT);
  printt(RED "<-x\n" DFT);
  AForm *a = new PresidentialPardonForm("Build");
  Bureaucrat b("Cleair", 73);

  std::cout << b << std::endl;

  b.signForm(*a);
  b.executeForm(*a);
  printt("\n");

  std::cout << *a << std::endl;

  delete a;

  printt(RED "x->" DFT);
  printt(YELLOW " Success grade to sing and fail execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *c = new PresidentialPardonForm("Plan");
  Bureaucrat d("Sail", 14);

  std::cout << d << std::endl;

  d.signForm(*c);
  d.executeForm(*c);
  printt("\n");

  std::cout << *c << std::endl;
  delete c;

  printt(RED "x->" DFT);
  printt(YELLOW " Success grade to sing and execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *e = new PresidentialPardonForm("Vue");
  Bureaucrat f("Bill", 4);

  std::cout << f << std::endl;

  f.signForm(*e);
  f.executeForm(*e);
  printt("\n");

  std::cout << *e << std::endl;
  delete e;

  printt(BLUE "-->" DFT);
  printt(GREEN " End test PresidentialPardonForm " DFT);
  printt(BLUE "<--\n" DFT);
}

void next(void) {
  std::string line;
  std::cout << GRAY "PRESS ENTER TO CONTINUE" DFT;
  std::getline(std::cin, line);
  system("clear");
}

int main() {
  testShrubbery();
  next();
  testRobotomyRequest();
  next();
  testPresidentialPardon();
  next();
  std::cout << RED "Bye baby!\n" DFT;
  return (0);
}
