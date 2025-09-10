#include "Common/Variable.h"
#include <iostream>

int main(int argc, char** argv) {

	Variable x("x");
	Variable y("y");
	Variable z("z");

	std::cout << (x * x * y + (y - z) / (x + z)).drawTree() << std::endl;

	return 0;
}