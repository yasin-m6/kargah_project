#include <iostream>
#include<iomanip>
#include "flight.hpp"

using namespace std;


air_hostes::air_hostes(string p_code , string recruitment_d , string f_name , string l_name , string n_code , string birth_d) : peaple(f_name , l_name , n_code , birth_d)
{
    try
    {
        set_personal_code(p_code);
    }
    catch( invalid_argument & e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        set_recruitment_day(recruitment_d);
    
    }
    catch( invalid_argument & e)
    {
        cerr << e.what() << endl;
    }
    
}


air_hostes::~air_hostes()
{

}

string air_hostes::get_perssonel_code() const
{
    string p_code;

    cout << "Enter your perssonel code : ";
    cin >> p_code;

    return p_code;
}

void air_hostes::set_personal_code(string perssonel_code)
{
    if (perssonel_code.size() != 4)
    {
        throw invalid_argument("perssonel code has to be 4 digits!!!!");
    }
    
    for (size_t i = 0; i < perssonel_code.size(); i++)
    {
        if (isdigit(perssonel_code[i]) != isdigit('1'))
        {
            throw invalid_argument("perssonel code has to be made by digits!!!!");
        }
    }

    this->perssonel_code = perssonel_code;
    
}

void air_hostes::set_recruitment_day(string recruitment_day)
{

    this->recruitment_day = recruitment_day;
}

void air_hostes::add_flight(flight * new_flight)
{
    work_list.push_back(new_flight);
}

void air_hostes::print_info()
{
    cout << setw(10) << first_name << "\t" << setw(10) << last_name << "\t" << setw(10) << perssonel_code << "\t" << setw(10) << recruitment_day << endl;
}

void air_hostes::print_work_list()
{
    cout << "pilot worklist" << endl;
    cout << setw(13) << "airplane code" << "\t" << setw(11) << "flight code" << "\t" << setw(10) << "flight day" << "\t" << setw(10) << "origin"  << setw(11) << "destination" << endl;
    for (size_t i = 0; i < work_list.size(); i++)
    {
        work_list[i]->print();
    }
    
}

void air_hostes::delete_from_worklist(string f_code)
{
    int find = -1;
    for (size_t i = 0; i < work_list.size(); i++)
    {
        if (work_list[i]->return_flight_code() == f_code)
        {
            find = i;
            break;
        }
        
    }

    if (find > -1)
    {
        work_list.erase(work_list.begin() + find);
    }
    
    
}