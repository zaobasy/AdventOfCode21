#include <iostream>
#include <vector>
#include <fstream>

#include <elevation.hpp>

ElevationMap::ElevationMap(std::vector<int> in_vec) {

    _size = in_vec.size();

    for (
        std::vector<int>::iterator it = in_vec.begin(); 
        it != in_vec.end(); 
        ++it
    ) {
        _map.push_back(*it);
    }

}

ElevationMap::ElevationMap(std::string filename) {

    std::ifstream in_file;
    int read_int;

    in_file.open(filename);

    if (in_file.is_open()) {
        while ( in_file ) {
            in_file >> read_int;
            _map.push_back(read_int);
        }
    }
    
    _size = _map.size() - 1;
    std::cout << "Read in " << _size << " values from file." << std::endl;

}

ElevationMap::~ElevationMap(){
    _size=0;
    _map.clear();
    _map.shrink_to_fit();
}

int ElevationMap::get_num_inc(int window_size){
    /*
    Calculate the number of elevation increases
    for rolling windows of provided size. Default
    is size value windows
    */

    int last_sum, curr_sum;
    int num_inc = 0;

    // initialize last_sum to first window
    last_sum = 0;
    for (int jdx=0; jdx < window_size; jdx++) {
        last_sum += _map[jdx];
    }

    // loop over all windows
    for (int idx=1; idx < _size-window_size+1; idx++){
        
        curr_sum = 0;

        for (int jdx=0; jdx < window_size; jdx++) {
            curr_sum += _map[idx+jdx];
        }

        if ( (curr_sum - last_sum) > 0 ) {
            num_inc += 1;
        }

        last_sum = curr_sum;

    }

    return num_inc;
}