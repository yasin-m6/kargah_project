#include <iostream>
#include<iomanip>
#include "flight.hpp"

using namespace std;

flight::flight(pilot* p_info , string f_code , string a_code , string o_city , string d_city , string f_day , string f_time)
{
    pilot_info.push_back(*p_info);
    flight_code = f_code;
    airplane_code = a_code;
    origin = o_city;
    destination = d_city;
    flight_day = f_day;
    flight_time = f_time;
    num_of_passengers = 0;
    money = 0;
}

flight::~flight()
{

}

string flight::get_airplane_code() const
{
    string a_code;

    cout << "airplane code is contain 5digits" << endl;
    cout << "Eneter airplane code : " ;
    cin >> a_code;

    return a_code;
}

void flight::set_airplane_code(string airplane_code)
{
    if (airplane_code.size() != 5)
    {
        throw invalid_argument("airplane code has 5digits!!!!!");
    }
    

    for (size_t i = 0; i < airplane_code.size(); i++)
    {
        if( isdigit(airplane_code[i]) != isdigit('1') )
        {
            throw invalid_argument("airplane code is just contain by digits!!!!");
        }
    }
    
}

string flight::get_flight_code() const
{
    string f_code;

    cout << "flight code is contain by 2 character and 4 digits" << endl;
    cout << "Eneter flight code : " ;
    cin >> f_code;

    return f_code;
}

void flight::set_flight_code(string flight_code)
{
    if (flight_code.size() != 6)
    {
        
    }

    for (int i = 0; i < flight_code.size() ; i++)
    {

        if (i < 2)
        {
            if ( (isalpha(flight_code[i]) != isalpha('a')) && (isalpha(flight_code[i]) != isalpha('A')) )
            {
                throw invalid_argument("flight code has to be start by 2alphabet!!!!");   
            }
            else
            {
                flight_code[i] = toupper(flight_code[i]);
            }
            
        }
        
        else if(i > 1)
        {
            if ( isdigit(flight_code[i]) != isdigit('1') )
            {
                throw invalid_argument("after 2 alphabet , has to be 4 digits!!!!");
            }
            
        }
    }
    
    this->flight_code = flight_code;
}


string flight::get_origin() const
{
    string origin_name;

    cout << "Eneter origin city's name : " ;
    cin >> origin_name;

    return origin_name;
}

void flight::set_origin(string origin)
{
    for (size_t i = 0; i < origin.size(); i++)
    {
        if( (isalpha(origin[i]) != isalpha('a')) && (isalpha(origin[i]) != isalpha('A') && origin[i] != ' ') )
        {
            throw invalid_argument("name of a city is just contain by alphabet and space!!!");
        }
    }

    this->origin = origin;
    
}

string flight::get_destination() const
{
    string dest_name;

    cout << "Eneter origin city's name : " ;
    cin >> dest_name;

    return dest_name;
}

void flight::set_destination(string destination)
{
    for (size_t i = 0; i < destination.size(); i++)
    {
        if( (isalpha(destination[i]) != isalpha('a')) && (isalpha(destination[i]) != isalpha('A')) )
        {
            throw invalid_argument("name of a city is just contain by alphabet and space!!!");
        }
    }

    this->destination = destination;
    
}

string flight::get_flight_day() const
{
    string flight_d;

    cout << "flight day is contain by 2 digits for day and month and 4 digits for year" << endl;
    cout << "put a space between each of them" << endl;
    cout << "Enter yor flight day : ";
    //cin >> flight_d.day >> flight_d.month >> flight_d.year;

    

    return  flight_d;
}


void flight::set_flight_day(string flight_day)
{
    

    this->flight_day = flight_day;
}

string flight::get_flight_time() const
{
    string flight_t;

    cout << "flight time is contain 2 digits for hours and 2 digits for minutes" << endl;
    cout << "put a space between each of them" << endl;
    cout << "Enter yor flight time : ";
    //cin >> flight_t.hour >> flight_t.min;

    return flight_t;
}

void flight::set_flight_time(string flight_time)
{
    

    this->flight_time = flight_time;
    
}

void flight::set_money()
{
    this->money = num_of_passengers * 10;
}

void flight::set_passengers_num()
{
    num_of_passengers = passengers_list.size();
}

void flight::add_to_air_hostes_list(air_hostes * new_air_hostes)
{
    air_hostes_list.push_back(*new_air_hostes);
}

void flight::add_to_passengers_list(passengers * new_passenger)
{
    passengers_list.push_back(*new_passenger);
}

void flight::change_pilot(pilot * new_pilot)
{
    pilot_info[0] =  *new_pilot;
}

void flight::print()
{
   cout << setw(6) << flight_code << "\t" << setw(6) << airplane_code << "\t" << setw(6) << pilot_info[0].return_personel_code() << "\t"; 
   cout << setw(10) <<flight_day << "\t" << setw(5) << flight_time << "\t" << setw(10) << origin << "\t" << setw(10) <<destination << "\t";
   cout << num_of_passengers << endl;
}

string flight::return_flight_code() const
{
    return flight_code;
}

string flight::return_pilot_code() const
{
    return pilot_info[0].return_personel_code();
}

string flight::return_flight_day() const
{
    return flight_day;
}

string flight::return_flight_time() const
{
    return flight_time;
}

string flight::return_origin() const
{
    return origin;
}

string flight::return_dest() const
{
    return destination;
}

string flight::return_airplane_code() const
{
    return airplane_code;
}

void flight::delete_from_pilot()
{
    pilot_info[0].delete_from_worklist(flight_code);
}

void flight::delete_from_air_hostess()
{
    for (size_t i = 0; i < air_hostes_list.size(); i++)
    {
        air_hostes_list[i].delete_from_worklist(flight_code);
    }
    
}