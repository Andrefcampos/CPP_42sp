
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << YELLOW "Please, put: ./converter [the string scalar];\n" \
		DFT << RED "Converts a valid scalar string to: " DFT \
		GRAY << "\n[char]: \n[int]: \n[float]: \n[double]:\n" DFT;
        return (1);
    }

    try {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception &ex) {
        std::cout << YELLOW "Error: " DFT << ex.what() << std::endl;
        return (1);
    }
    return (0);
}
