#include <iostream>
#include<iomanip>
#include "mashin_hamle_bar.hpp"
#include"flight.hpp"

mashin_hamle_bar::mashin_hamle_bar(string s , string ts)
{
    set_serial(s);
    set_tarikh_sakht(ts);
}


void mashin_hamle_bar::set_serial(string s)
{
    serial = s;
}
void mashin_hamle_bar::set_tarikh_sakht(string ts)
{
    tarikh_sakht = ts;
}

string mashin_hamle_bar::get_serial()
{
    return serial;
}

void mashin_hamle_bar::add_flight(flight * new_flight)
{
    work_list.push_back(new_flight);
}

void mashin_hamle_bar::print_info()
{
    cout << setw(6) << serial << "\t" << setw(10) << tarikh_sakht << endl;
}