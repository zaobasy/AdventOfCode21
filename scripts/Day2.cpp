#include <iostream>
#include <vector>

#include <submarine.hpp>

int main() {
	
	std::vector<Instruction> test_instructions = { 
				Instruction{"forward", 5},
				Instruction{"down", 5},
				Instruction{"forward", 8},
				Instruction{"up", 3},
				Instruction{"down", 8},
				Instruction{"forward", 2}
	};

	Submarine test_sub;
	std::cout << test_sub << std::endl;
	
	test_sub.apply_instructions(test_instructions);
	std::cout << test_sub << std::endl;


/*
	std::string input_file = "/Users/noether/Documents/GitHub/AdventOfCode21/input_files/Day1-Input1.txt";
	ElevationMap real_elevation(input_file);

	std::cout << "Real size: " << real_elevation.size() << std::endl;
	std::cout << "Num inc on real (window = 1): " << real_elevation.get_num_inc() << std::endl;
	std::cout << "Num inc on real (window = 3): " << real_elevation.get_num_inc(3) << std::endl;
*/
}
