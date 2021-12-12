#include <iostream>
#include <vector>
#include <fstream>

#include <submarine.hpp>

Submarine::Submarine(int init_horizontal, int init_depth)
    : _horizontal{init_horizontal}
    , _depth{init_depth} 
{ }


void Submarine::apply_instructions(
        std::vector<Instruction> in_insts
    ) {

        std::string type;
        int value;

        for (
            std::vector<Instruction>::iterator it = in_insts.begin();
            it != in_insts.end();
            it++
        ) {

            type = it->type;
            value = it->value;

            if (type == "forward") {
                _horizontal += value;
            } 
            else if (type == "up") {
                _depth -= value;
            } 
            else if (type == "down") {
                _depth += value;
            } 
            else {
                std::cout << "Unknown instruction " << type
                          << ", skipping this instruction."
                          << std::endl;
            }

        }
}


void read_instructions_from_file(
    std::string filename,
    std::vector<Instruction> *out_vec
) {

    std::ifstream in_file;
    std::string in_type;
    int in_value;
    Instruction in_inst{};

    in_file.open(filename);

    if (in_file.is_open()) {
        while ( in_file ) {

            in_file >> in_type >> in_value;

            if (!in_file.good())
                break;

            in_inst = {in_type, in_value};
            out_vec->push_back(in_inst);

        }
    }
    
    std::cout << "Read in " << out_vec->size()  
              << " instructions from file." << std::endl;

}