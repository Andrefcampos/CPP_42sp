
#include "Base.hpp"
#include <iostream>
#define println(x) std::cout << x

int main(void) {

  println(BLUE "===STARTING TESTS===\n" DFT);

  for (int i = 0; i < 8; ++i) {
    println(MAGENTA "===GENERATING BASE=== " DFT) << i + 1 << std::endl;
    println("\n");
    Base *ptr = generate();
    println(BLUE "===POINTER TEST===\n" DFT);
    identify(ptr);
    println(RED "===REFERENCE TEST===\n" DFT);
    identify(*ptr);
    println("\n");

    delete ptr;
  }

  return 0;
}
