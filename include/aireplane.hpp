#ifndef AIRPLANE
#define AIRPLANE

#include <string>
#include<vector>

using namespace std;

class flight;

class aireplane
{
    public:
        aireplane(string , int , string);
        string get_aireplane_serial();
        void set_airepalne_serial(string);
        void set_tedad_sndali(int);
        void set_tarikh_sakht(string);
        void add_flight(flight*);
        void print_info();

    protected:
        string airepalne_serial;
        int tedad_sndali;
        string tarikh_sakht;
        vector<flight*> work_list;
};





#endif