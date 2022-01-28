#ifndef PASSENGERS
#define PASSENGERS

#include "peaple.hpp"

class passengers : public peaple
{
    public:
        passengers(std::string , std::string , std::string , std::string , std::string);
        ~passengers();
        std::string get_name() const;
        void set_fathers_name(std::string);
        void print() const;
    private:
        std::string fathers_name; 
};

#endif