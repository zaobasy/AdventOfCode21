#include <iostream>

struct Instruction {
    std::string type;
    int value;
};

class Submarine {
    public:
        Submarine(int x=0, int d=0);
        ~Submarine() {};

        int get_horizontal() const { return _horizontal; }
        int get_depth() const { return _depth; }

        // given a vector of instructions, apply them
        void apply_instructions(std::vector<Instruction>);
    
    private:
        int _horizontal;
        int _depth;

};

// helper function to init vector of instructions
void read_instructions_from_file(std::string, std::vector<Instruction>*);

inline std::ostream& operator<<(std::ostream& os, const Submarine& sub)
{
    os << "Current position (horizon, depth): "
       << sub.get_horizontal()
       << ','
       << sub.get_depth();

    return os;
}