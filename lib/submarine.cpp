#include <iostream>
#include <vector>
#include <fstream>

#include <submarine.hpp>

Submarine::Submarine(int init_horizontal, int init_depth)
    : _horizontal{init_horizontal}
    , _depth{init_depth} 
{ }


void Submarine::apply_instructions(
        std::vector<Instruction> in_instructions
    ) {

        std::cout << "Do some stuff" << std::endl;
}


void read_instructions_from_file(
    std::string filename,
    std::vector<Instruction> out_vec
) {

    std::ifstream in_file;
    Instruction read_inst;

    in_file.open(filename);

    if (in_file.is_open()) {
        while ( in_file ) {
            in_file >> read_inst.type >> read_inst.value;
            out_vec.push_back(read_inst);
        }
    }
    
    std::cout << "Read in " << out_vec.size() -1  
              << " instructions from file." << std::endl;

}