/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:38:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/05 02:44:23 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

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

void mandatoryTest(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << GREEN "Top: " << mstack.top() << DFT << std::endl;
  mstack.pop();
  std::cout << CYAN "Size: " << mstack.size() << DFT << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << YELLOW "Stack: [";
  while (it != ite) {
    std::cout << *it; 
		++it;
	  if (it != ite) {
	    std::cout << ", ";
	  }
  }
  std::cout << "]" DFT << std::endl;
  std::stack<int> s(mstack);
}

void vectorTest(void) {
  MutantStack<int, std::vector<int> > mstack;

  std::cout << YELLOW "> Add number: 50;" DFT << std::endl;
  mstack.push(50);
  std::cout << YELLOW "> Add number: 170;" DFT << std::endl;
  mstack.push(170);
  std::cout << GREEN "Top: " << mstack.top() << DFT << std::endl;
  std::cout << RED "> Pop stack: 170;" DFT << std::endl;
  mstack.pop();
  std::cout << CYAN "Size: " << mstack.size() << DFT << std::endl;
  std::cout << YELLOW "> Add number: 31;" DFT << std::endl;
  mstack.push(31);
  std::cout << YELLOW "> Add number: 50;" DFT << std::endl;
  mstack.push(50);
  std::cout << YELLOW "> Add number: 767;" DFT << std::endl;
  mstack.push(767);
  //[...]
  std::cout << YELLOW "> Add number: 1000;" DFT << std::endl;
  mstack.push(1000);
  MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
  MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << YELLOW "Vector: [";
  while (it != ite) {
    std::cout << *it; 
		++it;
	  if (it != ite) {
	    std::cout << ", ";
	  }
  }
  std::cout << "]" DFT << std::endl;
  std::stack<int, std::vector<int> > s(mstack);
}

void listTest(void) {
  MutantStack<int, std::list<int> > mstack;

  std::cout << YELLOW "> Add number: 42;" DFT << std::endl;
  mstack.push(42);
  std::cout << YELLOW "> Add number: 35;" DFT << std::endl;
  mstack.push(35);
  std::cout << GREEN "Top: " << mstack.top() << DFT << std::endl;
  std::cout << RED "> Pop stack: 35;" DFT << std::endl;
  mstack.pop();
  std::cout << CYAN "Size: " << mstack.size() << DFT << std::endl;
  std::cout << YELLOW "> Add number: 21;" DFT << std::endl;
  mstack.push(21);
  std::cout << YELLOW "> Add number: 42;" DFT << std::endl;
  mstack.push(42);
  std::cout << YELLOW "> Add number: 5;" DFT << std::endl;
  mstack.push(5);
  //[...]
  std::cout << YELLOW "> Add number: 13;" DFT << std::endl;
  mstack.push(13);
  MutantStack<int, std::list<int> >::iterator it = mstack.begin();
  MutantStack<int, std::list<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << YELLOW "List: [";
  while (it != ite) {
    std::cout << *it; 
		++it;
	  if (it != ite) {
	    std::cout << ", ";
	  }
  }
  std::cout << "]" DFT << std::endl;
  std::stack<int, std::list<int> > s(mstack);
}

int main() {
  std::cout << BLUE "===== MANDATORY TEST: =====\n" DFT;
  mandatoryTest();
  std::cout << BLUE "===== END TEST: =====\n\n" DFT;
  std::cout << BLUE "===== VECTOR TEST: \n" DFT;
  vectorTest();
  std::cout << BLUE "===== END TEST: =====\n\n" DFT;
  std::cout << BLUE "===== LIST TEST: =====\n" DFT;
  listTest();
  std::cout << BLUE "===== END TEST: =====\n\n" DFT;
  return 0;
}
