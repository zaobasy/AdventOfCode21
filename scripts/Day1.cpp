#include <iostream>
#include <vector>

#include <elevation.hpp>

int main() {
	
	std::vector<int> test_map = { 
				199,
				200,
				208,
				210,
				200,
				207,
				240,
				269,
				260,
				263
	};

	ElevationMap test_elevation(test_map);

	std::cout << "Test size: " << test_elevation.size() << std::endl;
	std::cout << "Num inc on test (window = 1): " << test_elevation.get_num_inc() << std::endl;
	std::cout << "Num inc on test (window = 3): " << test_elevation.get_num_inc(3) << std::endl;

	std::string input_file = "/Users/noether/Documents/GitHub/AdventOfCode21/input_files/Day1-Input1.txt";
	ElevationMap real_elevation(input_file);

	std::cout << "Real size: " << real_elevation.size() << std::endl;
	std::cout << "Num inc on real (window = 1): " << real_elevation.get_num_inc() << std::endl;
	std::cout << "Num inc on real (window = 3): " << real_elevation.get_num_inc(3) << std::endl;
}
