#include <iostream>
#include <iomanip>
#include "passengers.hpp"

using namespace std;

passengers::passengers(string fathers_n , string f_name , string l_name , string n_code , string birth_d) : peaple(f_name , l_name , n_code , birth_d)
{

    while (1)
    {
        try
        {
            set_fathers_name(fathers_n);
            break;
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
            fathers_n = get_name();
            fflush(stdin);
        }   
    }

}

passengers::~passengers()
{

}

string passengers::get_name() const
{
    string name;

    cout << "Enter your father's name : ";
    cin >> name;

    return name;
}

void passengers::set_fathers_name(string fathers_name)
{
    for (size_t i = 0; i < fathers_name.size() ; i++)
    {
        if(isalpha(fathers_name[i]) != isalpha('a') && isalpha(fathers_name[i]) != isalpha('A') )
        {
            throw invalid_argument("father's name has to be contain by alphabets !!!!!");
        }
    }

    for (size_t i = 0; i < fathers_name.size() ; i++)
    {
        if(i == 0)
        {
            fathers_name[i] = toupper(fathers_name[i]);
        }
        else
        {
            fathers_name[i] = tolower(fathers_name[i]);
        }
    }
    
    this->fathers_name = fathers_name;
}

void passengers::print() const
{
    cout << setw(10) << first_name << setw(10) << last_name << setw(12) << national_code << setw(10) << fathers_name << setw(10) << birth_day << endl;
}