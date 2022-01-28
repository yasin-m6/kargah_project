#include <iostream>
#include <iomanip>
#include "ticket.hpp"
#include "flight.hpp"

using namespace std;


ticket::ticket(const flight * this_flight , string n , string l , string c , string mc , int p , int nerkh)
{
    serial_parvaz = this_flight->return_flight_code();
    serial_air = this_flight->return_airplane_code();
    mabda = this_flight->return_origin();
    maghsad = this_flight->return_dest();
    tharikh_parvaz = this_flight->return_flight_day();
    saat_parvaz = this_flight->return_flight_time();
    khalaban_code = this_flight->return_pilot_code();
    name = n;
    last_name = l;
    code_meli = c;
    mashin_code = mc;
    price = p;
    nerkh_sood = nerkh;
}

void ticket::set_serial_parvaz(string s)
{
    serial_parvaz = s;
}

void ticket::set_tharikh_parvaz(string t)
{
    tharikh_parvaz = t;
}

void ticket::set_saat_parvaz(string sp)
{
    saat_parvaz = sp;
}

void ticket::set_mabda(string mb)
{
    mabda = mb;
}

void ticket::set_maghsad(string mgh)
{
    maghsad = mgh; 
}

void ticket::set_name(string n)
{
    name = n;
}

void ticket::set_last_name(string l)
{
    last_name = l;
}

void ticket::set_code_meli(string c)
{
    code_meli = c;
}

void ticket::set_serial_air(string ser)
{
    serial_air = ser;
}

void ticket::set_khalaban_code(string khc)
{
    khalaban_code = khc;
}

void ticket::set_mashin_code(string mc)
{
    mashin_code = mc;
}

void ticket::set_price(int p)
{
    price = p;
}

void ticket::print_info()
{
    cout << setw(10) << name << "\t" << setw(10) << last_name << "\t" << setw(10) << code_meli << "\t" << setw(10) << mabda << "\t";
    cout << setw(10) << maghsad << "\t" << setw(10) << tharikh_parvaz << "\t" << setw(5) << saat_parvaz << "\t" << setw(6) << khalaban_code << "\t";
    cout << setw(6) << serial_parvaz << "\t" << setw(6) << serial_air << "\t" << setw(6) << mashin_code << endl;
}