#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
# define BLUE_GREEN	"\033[32;44m"
# define MAG_YE		"\033[33;45m"
# define RED     	"\033[1;31m"
# define GREEN   	"\033[1;32m"
# define YELLOW 	"\033[1;33m"
# define BLUE    	"\033[1;34m"
# define MAGENTA    "\033[1;35m"
# define CYAN    	"\033[1;36m"
# define WHITE    	"\033[1;37m"
# define ORANGE		"\033[0;38;5;166m"
# define GRAY		"\033[38;5;244m"
# define DFT   		"\033[0m"
# define NL         std::cout << '\n';
# define println(x) std::cout << x

int main() {
  NL
  println(GREEN "Starting tests with vector" DFT) << '\n';
  try {
        std::vector<int> vec;
        for (int i = 1; i <= 10; ++i) {
        println(YELLOW"Adding to vector value: ") << i << DFT << std::endl;
        vec.push_back(i);
        }
    } catch (const std::exception &e) {
       std::cerr << e.what() << std::endl;
    }
    NL;

  //   std::cout << GREEN("Trying to find number 3 in vector") << std::endl;
  //   std::vector<int>::iterator it = easyfind(vec, 3);
  //   std::cout << MAGENTA("Found in vector: ") << *it << std::endl;
  //   NL;

  //   std::cout << GREEN("Trying to find number 42 in vector") << std::endl;
  //   it = easyfind(vec, 42); // This should throw an exception
  // } catch (const std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // NL;
  // std::cout << GREEN("Starting tests with list") << std::endl;
  // try {
  //   std::list<int> lst;
  //   for (int i = 1; i < 10; ++i) {
  //     std::cout << YELLOW("Adding to list value: " << (i * 10)) << std::endl;
  //     lst.push_back(i * 10);
  //   }
  //   NL;
  //   std::cout << GREEN("Trying to find number 30 in list") << std::endl;
  //   std::list<int>::iterator it = easyfind(lst, 30);
  //   std::cout << MAGENTA("Found in list: ") << *it << std::endl;
  //   NL;

  //   std::cout << GREEN("Trying to find number 100 in list") << std::endl;
  //   it = easyfind(lst, 100); // This should throw an exception
  // } catch (const std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  return 0;
}
