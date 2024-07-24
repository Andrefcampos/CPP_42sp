
#include "iter.hpp"
#include <iostream>

#define println(x) std::cout << x

void	increment(int &num) {
	num++;
}

void	printNum(int &x) {
	println(x) << " <- Num\n";
}

int	main(void) {
	int	arr[5] = {1, 2, 3, 4, 5};

	println("Original arr: \n");
	iter(arr, 5, printNum);
	iter(arr, 5, increment);
	println("Modified arr: \n");
	iter(arr, 5, printNum);

	return 0;
}
