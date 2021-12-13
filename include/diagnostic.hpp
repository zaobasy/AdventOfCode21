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
        std::string const get_oxygen_generator() { return _oxygen_generator; }
        std::string const get_co2_scrubber() { return _co2_scrubber; }
        int const get_life_support() { return _life_support; }
    
    private:

        std::vector<std::string> _diagnostics;
        std::string _gamma_rate;
        std::string _oxygen_generator;
        std::string _co2_scrubber;
        std::string _epsilon_rate;
        int _power_consumption;
        int _life_support;

        void _set_gamma_rate();
        void _set_epsilon_rate();
        void _set_power_consumption();
        void _set_oxygen_generator();
        void _set_co2_scrubber();
        void _set_life_support();

        void _check_input();
        std::string _filter_diagnostics(std::string);
        std::string _get_max_min_string(std::vector<std::string>, std::string);

};
