
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#define println(x) std::cout << x

Base::~Base(void) {}

Base	*generate(void) {
	static bool	start = true;

	if (start) {
		std::srand(time(0));
		start = false;
	}
	int	number = std::rand() % 3;

	switch (number) {
		case (0) : {
			return (new A());
		} case (1) : {
			return (new B());
		} case (2) : {
			return (new C());
		}
	}
	return (0);
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		println(YELLOW "pointer type: " DFT);
		println(GREEN "A\n" DFT);
	} else if (dynamic_cast<B *>(p)) {
		println(YELLOW "pointer type: " DFT);
		println(GREEN "B\n" DFT);
	} else if (dynamic_cast<C *>(p)) {
		println(YELLOW "pointer type: " DFT);
		println(GREEN "C\n" DFT);
	} else {
		println(RED "error: bad casting!\n" DFT);
	}
}

void	identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		println(YELLOW "reference type: " DFT);
		println(GREEN "A\n" DFT);
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast<B &>(p);
		println(YELLOW "reference type: " DFT);
		println(GREEN "B\n" DFT);
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast<C &>(p);
		println(YELLOW "reference type: " DFT);
		println(GREEN "C\n" DFT);
	} catch (std::exception &e) {}
}
