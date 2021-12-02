#include <iostream>

class ElevationMap {
    public:
        ElevationMap();
        ~ElevationMap();

        int size();
        int get_num_inc();
        void init_from_file(std::string);
        void init_from_arr(int*);
    
    private:
        int *_map;
        int size;
}