/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 20:21:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <string>

#define printt(x) std::cout << x

void testShrubbery(void) {
  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test ShrubberyCreationForm " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(BLUE " Shrubbery success sign and execute form " DFT);
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
  printt(YELLOW " Shrubbery success sign and failed execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *c = new ShrubberyCreationForm("Build");
  Bureaucrat d("Jay", 138);

  std::cout << d << std::endl;

  d.signForm(*c);
  d.executeForm(*c);
  printt("\n");

  std::cout << *c << std::endl;

  delete c;

  printt(RED "x->" DFT);
  printt(YELLOW " Shrubbery failed sign and execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *e = new ShrubberyCreationForm("Town");
  Bureaucrat f("Mia", 149);

  std::cout << f << std::endl;

  f.signForm(*e);
  f.executeForm(*e);
  printt("\n");

  std::cout << *e << std::endl;

  delete e;

  printt(BLUE "-->" DFT);
  printt(GREEN " End test ShrubberyCreationForm " DFT);
  printt(BLUE "<--\n" DFT);
}

void testRobotomyRequest(void) {
  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test RobotomyRequestForm " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(BLUE " RobotomyRequest success sign and execute form " DFT);
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
  printt(YELLOW " RobotomyRequest success sign and failed execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *c = new RobotomyRequestForm("Movel");
  Bureaucrat d("Ramires", 47);

  std::cout << d << std::endl;

  d.signForm(*c);
  d.executeForm(*c);
  printt("\n");

  std::cout << *c << std::endl;

  delete c;

  printt(RED "x->" DFT);
  printt(YELLOW " RobotomyRequest failed sign and execute form " DFT);
  printt(RED "<-x\n" DFT);

  AForm *e = new RobotomyRequestForm("Bike");
  Bureaucrat f("Tay", 47);

  std::cout << f << std::endl;

  f.signForm(*e);
  f.executeForm(*e);
  printt("\n");

  std::cout << *e << std::endl;

  delete e;

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
  printt(GREEN " Success grade to sing and execute form " DFT);
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

void testIntern(void) {

  printt(BLUE "\n-->" DFT);
  printt(GREEN " Start test Intern " DFT);
  printt(BLUE "<--\n" DFT);

  printt(RED "x->" DFT);
  printt(GREEN " Intern call RobotomyRequest " DFT);
  printt(RED "<-x\n" DFT);

  Intern someRandomIntern;
  AForm *rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");

  Bureaucrat b1("Harley", 10);
  Bureaucrat b2("Freud", 45);

  b1.signForm(*rrf);
  b1.executeForm(*rrf);
  std::cout << b1 << std::endl;
  printt("\n");

  b2.signForm(*rrf);
  b2.executeForm(*rrf);
  std::cout << b2 << std::endl;
  printt("\n");

  std::cout << *rrf << std::endl;

  delete rrf;

  printt(RED "x->" DFT);
  printt(GREEN " Intern call ShrubberyCreation " DFT);
  printt(RED "<-x\n" DFT);

  Intern intern;
  AForm *SCF = intern.makeForm("shrubbery creation", "Churchill");

  Bureaucrat b3("Mart", 136);
  Bureaucrat b4("Carl", 145);
  b3.signForm(*SCF);
  b3.executeForm(*SCF);
  std::cout << b3 << std::endl;
  printt("\n");

  b4.signForm(*SCF);
  b4.executeForm(*SCF);
  std::cout << b4 << std::endl;
  printt("\n");

  std::cout << *SCF << std::endl;

  delete SCF;

  printt(RED "x->" DFT);
  printt(GREEN " Intern call PresidentialPardon " DFT);
  printt(RED "<-x\n" DFT);

  Intern intern2;
  AForm *PPF = intern2.makeForm("presidential pardon", "Bler");

  Bureaucrat b5("Takeo", 4);
  Bureaucrat b6("Ismael", 26);
  b5.signForm(*PPF);
  b5.executeForm(*PPF);
  std::cout << b5 << std::endl;
  printt("\n");

  b6.signForm(*PPF);
  b6.executeForm(*PPF);
  std::cout << b6 << std::endl;
  printt("\n");

  std::cout << *PPF << std::endl;

  delete PPF;

  printt(BLUE "\n-->" DFT);
  printt(GREEN " End test Intern " DFT);
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
  testIntern();
  next();
  std::cout << RED "Bye Bye!\n\n" DFT;
  return (0);
}
