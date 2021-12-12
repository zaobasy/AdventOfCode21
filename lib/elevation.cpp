#include <elevation.hpp>

void ElevationMap::init_from_arr(int *in_arr) {

    _size = *(&in_arr + 1) - in_arr;

    _map = new int[_size];

    for (int i=0; i < _size; i++) {
        _map[i] = in_arr[i];
    }
}

