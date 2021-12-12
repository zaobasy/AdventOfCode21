#include <iostream>
#include <vector>

class Diagnostic {
    public:
        Diagnostic(std::vector<std::string>); // init from array
        Diagnostic(std::string); // init from file
        ~Diagnostic();

        std::string const get_gamma_rate() { return _gamma_rate; }
        std::string const get_epsilon_rate() { return _epsilon_rate; }
        int const get_power_consumption() { return _power_consumption; }
    
    private:

        std::vector<std::string> _diagnostics;
        std::string _gamma_rate;
        std::string _epsilon_rate;
        int _power_consumption=-1;

        void _set_gamma_rate();
        void _set_epsilon_rate();
        void _set_power_consumption();
        void _check_input();

};
