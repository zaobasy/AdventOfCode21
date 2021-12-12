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
	std::cout << "Product: " 
			  << test_sub.get_depth()*test_sub.get_horizontal()
			  << std::endl;

	Submarine real_sub;
	std::vector<Instruction> real_instructions;
	std::string input_file = "/Users/noether/Documents/GitHub/AdventOfCode21/input_files/Day2-Input1.txt";
	
	read_instructions_from_file(input_file, &real_instructions);
	real_sub.apply_instructions(real_instructions);

	std::cout << real_sub << std::endl;
	std::cout << "Product: " 
			  << real_sub.get_depth()*real_sub.get_horizontal()
			  << std::endl;
}
