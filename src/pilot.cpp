#include<iostream>
#include<iomanip>
#include "flight.hpp"

using namespace std;

pilot::pilot(int deg , string p_code , string r_day , string f_name , string l_name , string n_code , string birth_d) : air_hostes(p_code , r_day , f_name , l_name , n_code , birth_d)
{
    while (1)
    {
        try
        {
            set_degree(deg);
            break;
        }
        catch( invalid_argument & e)
        {
            cerr << e.what() << endl;
            deg = get_degree();
        }
        
    }
    
}

pilot::~pilot()
{

}

int pilot::get_degree() const
{
    int deg;

    cout << "first class = 1  / second class = 2 / third class = 3" << endl;
    cout << "enter yor degree : ";
    cin >> deg;

    return deg;
}

void pilot::set_degree(int pilots_degree)
{
    /*if(pilots_degree < 1 && pilots_degree > 3)
    {
        throw invalid_argument("there is only three degrees!!!");
    }*/
    this->pilots_degree = pilots_degree;
}

void pilot::add_flight(flight * new_flight)
{
    work_list.push_back(new_flight);
}

void pilot::print() const
{
    cout << setw(10) << first_name << "\t" << setw(10) << last_name << "\t" << setw(10) << perssonel_code << "\t" << setw(10) << recruitment_day  << "\t" << setw(6) << pilots_degree << endl;
}

void pilot::print_work_list()
{
    cout << "pilot worklist" << endl;
    cout << setw(13) << "airplane code" << "\t" << setw(11) << "flight code" << "\t" << setw(10) << "flight day" << "\t" << setw(10) << "origin"  << setw(11) << "destination" << endl;
    for (size_t i = 0; i < work_list.size(); i++)
    {
        work_list[i]->print();
    }
    
}

string pilot::return_personel_code() const
{
    return perssonel_code;
}

void pilot::delete_from_worklist(string f_code)
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