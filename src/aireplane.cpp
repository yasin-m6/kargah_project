#include <iostream>
#include<iomanip>
#include "aireplane.hpp"
#include"flight.hpp"



aireplane::aireplane(string as , int t , string ts)
{
    set_airepalne_serial(as);
    set_tedad_sndali(t);
    set_tarikh_sakht(ts);
}

void aireplane::set_airepalne_serial(string as)
{
    airepalne_serial = as;
}

void aireplane::set_tedad_sndali(int t)
{
    tedad_sndali = t;
}

void aireplane::set_tarikh_sakht(string ts)
{
    tarikh_sakht = ts;
}

void aireplane::add_flight(flight * new_flight)
{
    work_list.push_back(new_flight);
}

string aireplane::get_aireplane_serial()
{
    return airepalne_serial;
}

void aireplane::print_info()
{
    cout << setw(6) << airepalne_serial << "\t" << setw(3) << tedad_sndali << "\t" << setw(10) << tarikh_sakht << endl;
}