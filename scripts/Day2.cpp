#include <iostream>
#include <vector>

#include <submarine.hpp>

void print_soln(Submarine *sub)
{

	std::cout << *sub << std::endl;
	std::cout << "Product: " 
			  << sub->get_depth()*sub->get_horizontal()
			  << std::endl;
}

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
	
	test_sub.apply_basic_instructions(test_instructions);
	print_soln(&test_sub);
	
	test_sub = Submarine();
	test_sub.apply_complex_instructions(test_instructions);
	print_soln(&test_sub);

	Submarine real_sub;
	std::vector<Instruction> real_instructions;
	std::string input_file = "/Users/noether/Documents/GitHub/AdventOfCode21/input_files/Day2-Input1.txt";
	
	read_instructions_from_file(input_file, &real_instructions);
	
	real_sub.apply_basic_instructions(real_instructions);
	print_soln(&real_sub);

	real_sub = Submarine();
	real_sub.apply_complex_instructions(real_instructions);
	print_soln(&real_sub);

}
