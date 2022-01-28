#ifndef AIR_HOSTES
#define AIR_HOSTES

#include <vector>
#include "peaple.hpp"

class flight;

class air_hostes : public peaple
{
    public:
        air_hostes(std::string , std::string , std::string , std::string , std::string , std::string);
        ~air_hostes();
        std::string get_perssonel_code() const;
        void set_personal_code(std::string); 
        std::string get_recruitment_day() const;
        void set_recruitment_day(std::string);
        void add_flight(flight*);
        void print_info();
        void print_work_list();
        void delete_from_worklist(std::string);

    protected:
        std::string perssonel_code;
        std::string recruitment_day; 
        std::vector <flight*> work_list;
};

#endif