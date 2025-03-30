#include <iostream>
#include "complex_number.hpp"

int main(void) {
    using com = complex_number<double>;
    
    com c1(2,3);
    com c2(1,6);

    std::cout << "Numero complesso c1: " << c1 << std::endl;
    std::cout << "Numero complesso c2: " << c2 << std::endl;


	std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
	std::cout << c1 << " * " << c2 << " = " << c1*c2 << std::endl;
    com c3 = c1+c2;
    std::cout << "The conjugate of " << c3 << " is " << c3.conj() << "; " << std::endl;
	com c5 = com(4,5) + 2.0;
	std::cout << "(4+5i) + 2 = " << c5 << std::endl;

    return 0;
}
