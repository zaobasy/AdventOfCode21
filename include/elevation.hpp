#include <iostream>
#include <vector>

class ElevationMap {
    public:
        ElevationMap(std::vector<int>); // init from array
        ElevationMap(std::string); // init from file
        ~ElevationMap();

        int size() { return _size; }
        int get_num_inc(int x=1);
    
    private:
        std::vector<int> _map;
        int _size;
};