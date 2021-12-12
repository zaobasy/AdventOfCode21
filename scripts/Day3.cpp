#include <iostream>
#include <vector>

#include <diagnostic.hpp>


void print_soln(Diagnostic *diag)
{
	std::string value;

	value = diag->get_gamma_rate();
	std::cout << "Gamma rate: "  << value
			  << " " << std::stoi(value,0,2) << std::endl;

	value = diag->get_epsilon_rate();
	std::cout << "Epsilon rate: "  << value
			  << " " << std::stoi(value,0,2) << std::endl;
	
	std::cout << "Power consumption: "
			  << diag->get_power_consumption() << std::endl;
}


int main() {
	
	std::vector<std::string> test_input = { 
				"00100",
				"11110",
				"10110",
				"10111",
				"10101",
				"01111",
				"00111",
				"11100",
				"10000",
				"11001",
				"00010",
				"01010"
	};

	Diagnostic test_diag(test_input);
	print_soln(&test_diag);

	std::string input_file = "/Users/noether/Documents/GitHub/AdventOfCode21/input_files/Day3-Input1.txt";
	Diagnostic real_diag(input_file);
	print_soln(&real_diag);


}
