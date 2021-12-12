#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

#include <diagnostic.hpp>

Diagnostic::Diagnostic(std::vector<std::string> in_vec) {

    for (
        std::vector<std::string>::iterator it = in_vec.begin(); 
        it != in_vec.end(); 
        ++it
    ) {
        _diagnostics.push_back(*it);
    }

    // power consumption will set gamma and epsilon too
    _check_input();
    _set_power_consumption();

}

Diagnostic::Diagnostic(std::string filename) {

    std::ifstream in_file;
    std::string line;

    in_file.open(filename);

    if (in_file.is_open()) {
        while ( in_file ) {
            in_file >> line;

            if (!in_file.good())
                break;

            _diagnostics.push_back(line);
        }
    }
    
    int size = _diagnostics.size();
    std::cout << "Read in " << size << " values from file." << std::endl;

    // power consumption will set gamma and epsilon too
    _check_input();
    _set_power_consumption();
}


Diagnostic::~Diagnostic(){
    _diagnostics.clear();
    _diagnostics.shrink_to_fit();
}


void Diagnostic::_check_input(){

    std::string msg;
    char ch_value;
    bool error = false;
    int input_len = _diagnostics[0].size();

    for (
        std::vector<std::string>::iterator it = _diagnostics.begin(); 
        it != _diagnostics.end(); 
        ++it
    ) {
    
        // check input size
        if ( it->size() != input_len){
            msg = "Input sizes do not match";
            error = true;
            break;
        }

        // check character values
        for (
            std::string::iterator ch = it->begin();
            ch != it->end();
            ++ch
        ){
            ch_value = char(*ch);
            if (ch_value != '0' && ch_value != '1') {
                msg = "Unknow bit char in " + *it;
                error = true;
                break;
            }
        }

        if (error)
            break;

    }

    if (error)
        throw std::runtime_error(msg);
    else
        std::cout << "Inputs are valid" << std::endl;
}


void Diagnostic::_set_gamma_rate(){

    if (_gamma_rate.size() != 0) {
        std::cout << "_gamma_rate already set, skipping" << std::endl;
        return;
    }

    int total_lines=0;
    int *count_ones;

    int len = _diagnostics[0].size();
    count_ones = new int[len];

    // initialize counts
    for (int idx=0; idx < len; idx++){
        count_ones[idx] = 0;
    }

    // loop over diagnostics and get counts
    for (
        std::vector<std::string>::iterator it = _diagnostics.begin(); 
        it != _diagnostics.end(); 
        ++it
    ) {
        total_lines++;

        for (int idx=0; idx < len; idx++){
            if (it->at(idx) == '1') 
                count_ones[idx]++;
        }
    }

    // calculate out string
    for (int idx=0; idx < len; idx++){
        if (count_ones[idx] > total_lines/2)
            _gamma_rate += '1';
        else if (count_ones[idx] < total_lines/2)
            _gamma_rate += '0';
        else
            throw std::runtime_error("Equal 1s and 0s");
    }

}


void Diagnostic::_set_epsilon_rate(){

    if (_gamma_rate.size() == 0){
        std::cout << "gamma_rate not yet calculated,"
                  << " will calculate before epsilon_rate"
                  << std::endl;
        _set_gamma_rate();
    }

    int len = _gamma_rate.size();

    // invert chars
    for (int idx=0; idx < len; idx++){
        if (_gamma_rate[idx] == '1')
            _epsilon_rate += '0';
        else if (_gamma_rate[idx] == '0')
            _epsilon_rate += '1';
        else
            throw std::runtime_error("Invalid gamma rate " + _gamma_rate);
    }

}

void Diagnostic::_set_power_consumption(){

    _set_gamma_rate();
    _set_epsilon_rate();

    _power_consumption = std::stoi(_gamma_rate,0,2)
                        *std::stoi(_epsilon_rate,0,2);

}