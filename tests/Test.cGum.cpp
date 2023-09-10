#include <iostream>
import cGum;


auto bajs (int*) -> void {
	// std::cout << "cleanup hihi!" << std::endl;
}



auto main (int argc, char** argv) -> int {

	// [[cleanup (bajs)]] int var_alias = 1;
	int var_alias __attribute__ ((cleanup (bajs))) = 1;

	// auto floats = v_floats {1, 2, 3, 4};
	// auto new_floats = floats * 5;

	std::cout << "Test for cGum done!" << std::endl;
	return 0;
}