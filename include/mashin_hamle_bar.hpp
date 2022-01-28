#ifndef MASHIN_HAMLE_BAR
#define MASHIN_HAMLE_BAR

#include <string>
#include <vector>

using namespace std;

class flight;

class mashin_hamle_bar
{
    public:
    mashin_hamle_bar(string , string);
        void set_serial(string);
        string get_serial();
        void set_tarikh_sakht(string);
        void add_flight(flight *);
        void print_info();
    private:
        string serial;
        string tarikh_sakht;
        vector<flight*> work_list;
};



#endif