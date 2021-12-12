#include <iostream>

struct Instruction {
    std::string type;
    int value;
};

class Submarine {
    public:
        Submarine(int x=0, int d=0, int a=0);
        ~Submarine() {};

        int get_horizontal() const { return _horizontal; }
        int get_depth() const { return _depth; }
        int get_aim() const { return _aim; }

        // given a vector of instructions, apply them
        void apply_basic_instructions(std::vector<Instruction>);
        void apply_complex_instructions(std::vector<Instruction>);
    
    private:
        int _horizontal;
        int _depth;
        int _aim;

};

// helper function to init vector of instructions
void read_instructions_from_file(std::string, std::vector<Instruction>*);

inline std::ostream& operator<<(std::ostream& os, const Submarine& sub)
{
    os << "Current position (horizon, depth, aim): "
       << sub.get_horizontal()
       << ',' << sub.get_depth()
       << ',' << sub.get_aim();

    return os;
}