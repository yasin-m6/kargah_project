#ifndef TICKET
#define TICKET

#include <string>
#include "flight.hpp"

using namespace std;

class ticket
{

    public:
        ticket(const flight *, string , string , string , string , int , int);
        void set_serial_parvaz(string);
        void set_tharikh_parvaz(string);
        void set_saat_parvaz(string);
        void set_mabda(string);
        void set_maghsad(string);
        void set_name(string);
        void set_last_name(string);
        void set_code_meli(string);
        void set_serial_air(string);
        void set_khalaban_code(string);
        void set_mashin_code(string);
        void set_price(int);
        void set_nerkh(int);
        void print_info();


    private:
        string serial_parvaz;
        string tharikh_parvaz;
        string saat_parvaz;
        string mabda;
        string maghsad;
        string name;
        string last_name;
        string code_meli;
        string serial_air;
        string khalaban_code;
        string mashin_code;
        int price;
        int nerkh_sood;

};






#endif