#include <iostream>
#include"flight.hpp"
#include"aireplane.hpp"
#include"mashin_hamle_bar.hpp"
#include "ticket.hpp"

void add_new_pilot(vector<pilot> &);
void add_new_air_hostes(vector<air_hostes> &);
void add_new_airplane(vector<aireplane> &);
void add_new_ticket(vector<vector<ticket>> &, vector<flight> & , vector<mashin_hamle_bar>&);
void add_new_flight(vector<flight> &, vector<pilot> & , vector<vector<ticket>> & , vector<aireplane>&);
void add_new_mashin(vector<mashin_hamle_bar> &);
void delete_from_pilots(vector<pilot> &);
void delete_from_air_hostes(vector<air_hostes> &);
void delete_from_airplane(vector<aireplane> &);
void delete_from_flights(vector<flight> & , vector<vector <ticket>>&);
void delete_from_tickets(vector<vector<ticket>> & , vector<flight> &);
void delete_from_mashins(vector<mashin_hamle_bar> &);

using namespace std;


int main()
{

    string comand;

    vector <pilot> pilots_list;
    vector <air_hostes> air_hostes_list;
    vector <flight> flight_list;
    vector <aireplane> airplanes_list;
    vector <mashin_hamle_bar> mashins_list;
    vector < vector<ticket> > tickets_list;
    while (1)
    {
        cout << "**************************************************************" << endl;
        cout << " command list " << endl;
        cout << " create_ticket " << endl; 
        cout << " add_airplane " << endl;
        cout << " add_mashin " << endl;
        cout << " add_air_hostes " << endl;
        cout << " add_pilot" << endl;
        cout << " add_flight" << endl;
        cout << " add_air_hostes_to_flight" << endl;
        cout << " delete_ticket " << endl; 
        cout << " delete_airplane " << endl;
        cout << " delete_mashin " << endl;
        cout << " delete_air_hostes " << endl;
        cout << " delete_pilot" << endl;
        cout << " delete flight" << endl;
        cout << " anything else : Exit " << endl;
        cout << " entr one of above command " << endl;
        cout << "************************************************************" << endl;
        cout << "comand : " << endl;
        cin >> comand;


        if (comand == "create_ticket")
        {
            add_new_ticket(tickets_list , flight_list , mashins_list);
        }
        else if (comand == "add_airplane")
        {
            add_new_airplane(airplanes_list);
        }
        else if (comand == "add_mashin")
        {
            add_new_mashin(mashins_list);
        }
        else if (comand == "add_air_hostes")
        {
            add_new_air_hostes(air_hostes_list);
        }
        else if (comand == "add_pilot")
        {
            add_new_pilot(pilots_list);
        }
        else if (comand == "add_flight")
        {
            add_new_flight(flight_list , pilots_list , tickets_list , airplanes_list);
        }
        else if(comand == "add_air_hostes_to_flight")
        {
            
        }
        else if (comand == "delete_ticket")
        {
            delete_from_tickets(tickets_list , flight_list);
        }
        else if (comand == "delete_airplane")
        {
            delete_from_airplane(airplanes_list);
        }
        else if (comand == "delete_mashin")
        {
            delete_from_mashins(mashins_list);
        }
        else if (comand == "delete_air_hostes")
        {
            delete_from_air_hostes(air_hostes_list);
        }
        else if (comand == "delete_pilot")
        {
            delete_from_pilots(pilots_list);
        }
        else if (comand == "delete_flight")
        {
            delete_from_flights(flight_list , tickets_list);
        }
        else
        {
            break;
        }
    }
        
    return 0;
}

void add_air_hostes_to_flight(vector<flight> & flights_list , vector<air_hostes> & air_hostes_list)
{
    int find = 0;
    int choose = 0;
    cout << "**********************************************" << endl;
    cout << "flight codes : " << endl;
    for (size_t i = 0; i < flights_list.size(); i++)
    {
        cout << i+1 << ") " << flights_list[i].return_flight_code() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter flights number : ";
    cin >> find;   

    if (find > 0 && find < flights_list.size() + 1)
    {
        cout << "**********************************************" << endl;
        cout << "air hostes : " << endl;
        for (size_t i = 0; i < air_hostes_list.size(); i++)
        {
            cout << i+1 << ") "; 
            air_hostes_list[i].print_info();
        }
        cout << "**********************************************" << endl;
        cout << "enter air_hostes number : ";
        cin >> choose;   

        if (choose > 0 && choose < air_hostes_list.size() + 1)
        {
            air_hostes_list[choose].add_flight(&flights_list[find]);//ezafe kardan parvaz be list karhaye mehmandar
            flights_list[find].add_to_air_hostes_list(&air_hostes_list[choose]);//ezafe kardan mehmandar be list mehmandar haye parvaz
        }
        
    }
    
}

void add_new_pilot(vector<pilot> & pilots_list)
{
    string f_name;
    string l_name;
    string n_code;//code meli
    string p_code;//code personeli
    int degree;//daraje
    string b_day;//tarikh tavalod
    string r_day;//tarikh estekhdam

    cout << "enter your first name : ";
    cin >> f_name;
    cout << "enter your last name : ";
    cin >> l_name;
    cout << "enter your national code : ";
    cin >> n_code;
    cout << "enter your personel code : ";
    cin >> p_code;
    cout << "enter your degree : ";
    cin >> degree;
    cout << "enter your birth day : ";
    cin >> b_day;
    cout << "enter your recruitment day : ";
    cin >> r_day;

    pilots_list.push_back(pilot(degree , p_code , r_day , f_name , l_name , n_code , b_day));
}



void add_new_air_hostes(vector<air_hostes> & air_hostes_list)
{
    string f_name;
    string l_name;
    string n_code;//code meli
    string p_code;//code personeli
    string b_day;//tarikh tavalod
    string r_day;//tarikh estekhdam
    cout << "enter your first name : ";
    cin >> f_name;
    cout << "enter your last name : ";
    cin >> l_name;
    cout << "enter your national code : ";
    cin >> n_code;
    cout << "enter your personel code : ";
    cin >> p_code;
    cout << "enter your birth day : ";
    cin >> b_day;
    cout << "enter your recruitment day : ";
    cin >> r_day;

    air_hostes_list.push_back(air_hostes(p_code , r_day , f_name , l_name , n_code , b_day));
}

void add_new_ticket(vector<vector<ticket>> & tickets_list , vector<flight> & flights_list , vector<mashin_hamle_bar> & mashins_list)
{
    string fathers_name;
    string f_name;
    string l_name;
    string n_code;//code meli
    string b_day;//tarikh tavalod
    string serial_parvaz;
    string mashin_code;
    int find = -1;
    int choose = -1;

    cout << "enter your first name : ";
    cin >> f_name;
    cout << "enter your last name : ";
    cin >> l_name;
    cout << "enter your national code : ";
    cin >> n_code;
    cout << "enter your birth day : ";
    cin >> b_day;
    cout << "enter your fathers name : ";
    cin >> fathers_name;
    cout << "**********************************************" << endl;
    cout << "mashin codes : " << endl;
    for (size_t i = 0; i < mashins_list.size(); i++)
    {
        cout << mashins_list[i].get_serial() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter mashin code : ";
    cin >> mashin_code;

    cout << "**********************************************" << endl;
    cout << "flight codes : " << endl;
    for (size_t i = 0; i < flights_list.size(); i++)
    {
        cout << flights_list[i].return_flight_code() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter flight code : ";
    cin >> serial_parvaz;
    
    for (size_t i = 0; i < flights_list.size(); i++)
    {
        if (flights_list[i].return_flight_code() == serial_parvaz)
        {
            find = i;
            break;
        }
        
    }
    for (size_t i = 0; i < mashins_list.size(); i++)
    {
        if (mashins_list[i].get_serial() == mashin_code)
        {
            choose = i;
            break;
        }
        
    }
    
    if (find > -1 && choose > -1)
    {
        tickets_list[find].push_back(ticket(&flights_list[find] , f_name , l_name , n_code , mashin_code , 10 , 2));
        passengers new_passenger( fathers_name , f_name , l_name , n_code , b_day);
        flights_list[find].add_to_passengers_list(&new_passenger);//ezafe kardan be list mosaferan
        mashins_list[choose].add_flight(&flights_list[find]);//ezafe kardan parvaz be karhaye mashin hamle bar
    }
    else
    {
        cout << "there isnt any flight with this code!!!" << endl;
    }
    
}

void add_new_flight(vector<flight> & flights_list , vector<pilot> & pilots_list , vector<vector<ticket>> & tickets_list, vector<aireplane>& aireplanes_list)
{
    string f_code;
    string a_code;
    string o_city;
    string d_city;
    string f_day;
    string f_time;
    string pilot_code;
    int find = -1;
    int choose = -1;

    cout << "enter your flight code : ";
    cin >> f_code;

    cout << "**********************************************" << endl;
    cout << "pilots personal code : "<< endl;
    for (size_t i = 0; i < aireplanes_list.size(); i++)
    {
        cout << aireplanes_list[i].get_aireplane_serial() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter your airplane code : ";
    cin >> a_code;

    cout << "enter your origin city : ";
    cin >> o_city;
    cout << "enter your dest city : ";
    cin >> d_city;
    cout << "enter your flight day : ";
    cin >> f_day;
    cout << "enter flight time : ";
    cin >> f_time;

    cout << "**********************************************" << endl;
    cout << "pilots personal code : "<< endl;
    for (size_t i = 0; i < pilots_list.size(); i++)
    {
        cout << pilots_list[i].return_personel_code() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter pilot personel code : ";
    cin >> pilot_code;

    for (size_t i = 0; i < pilots_list.size(); i++)
    {
        if (pilots_list[i].return_personel_code() == pilot_code)
        {
            find = i;
            break;
        } 
    }
    for (size_t i = 0; i < aireplanes_list.size(); i++)
    {
        if (aireplanes_list[i].get_aireplane_serial() == a_code)
        {
            choose = i;
            break;
        } 
    }
    
    if (find > -1 && choose > -1)
    {
        flights_list.push_back(flight(&pilots_list[find] , f_code , a_code , o_city , d_city , f_day , f_time));
        tickets_list.push_back(vector<ticket>());//ezafe kardan yek khane jadid baraye bilit haye in parvaz
        pilots_list[find].add_flight(&flights_list[ flights_list.size() - 1 ]);//ezafe kardan hamin parvaz be list parvaz haye khalaban
        aireplanes_list[choose].add_flight(&flights_list[ flights_list.size() - 1 ]);
    }
    

}

void add_new_airplane(vector<aireplane> & airplanes_list)
{
    string a_code;
    string tarikh_sakht;
    int tedad_sandali;

    cout << "enter airplane code : ";
    cin >> a_code;
    cout << "enter tarikh sakht : ";
    cin >> tarikh_sakht;
    cout << "enter tedad sandali : ";
    cin >> tedad_sandali;

    airplanes_list.push_back(aireplane(a_code , tedad_sandali , tarikh_sakht));
}

void add_new_mashin(vector<mashin_hamle_bar> & mashins_list)
{
    string m_code;
    string tarikh_sakht;
    cout << "enter mashin code : ";
    cin >> m_code;
    cout << "enter tarikh sakht : ";
    cin >> tarikh_sakht;

    mashins_list.push_back(mashin_hamle_bar(m_code , tarikh_sakht));
}



void delete_from_pilots(vector<pilot> & pilots_list)
{
    int choose = -1;
    char taaid;
    for (size_t i = 0; i < pilots_list.size(); i++)
    {
        cout << i+1 << ")\t";
        pilots_list[i].print();
    }

    cout << "enter number of pilot you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= pilots_list.size())
    {
        cout << "do you want to delete this pilot?" << endl;
        pilots_list[choose - 1].print();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            pilots_list.erase(pilots_list.begin() + choose);
            cout << "pilot is deleted :)" << endl;
        }
        
    }
    
    
}

void delete_from_air_hostes(vector<air_hostes> & air_hostes_list)
{
    int choose = -1;
    char taaid;
    for (size_t i = 0; i < air_hostes_list.size(); i++)
    {
        cout << i+1 << ")\t";
        air_hostes_list[i].print_info();
    }

    cout << "enter number of air hostess you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= air_hostes_list.size())
    {
        cout << "do you want to delete this air hostess?" << endl;
        air_hostes_list[choose - 1].print_info();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            air_hostes_list.erase(air_hostes_list.begin() + choose);
            cout << "air hostess is deleted :)" << endl;
        }
        
    }
    
    
}

void delete_from_airplane(vector<aireplane> & airplanes_list)
{
    int choose = -1;
    char taaid;
    for (size_t i = 0; i < airplanes_list.size(); i++)
    {
        cout << i+1 << ")\t";
        airplanes_list[i].print_info();
    }

    cout << "enter number of pilot you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= airplanes_list.size())
    {
        cout << "do you want to delete this pilot?" << endl;
        airplanes_list[choose - 1].print_info();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            airplanes_list.erase(airplanes_list.begin() + choose);
            cout << "pilot is deleted :)" << endl;
        }
        
    }
    
    
}

void delete_from_flights(vector<flight> & flights_list , vector<vector <ticket>> & tickets_list)
{
    int choose = -1;
    char taaid;
    for (size_t i = 0; i < flights_list.size(); i++)
    {
        cout << i+1 << ")\t";
        flights_list[i].print();
    }

    cout << "enter number of flight you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= flights_list.size())
    {
        cout << "do you want to delete this flight?" << endl;
        flights_list[choose - 1].print();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            flights_list[choose].delete_from_air_hostess();
            flights_list[choose].delete_from_pilot();
            flights_list.erase(flights_list.begin() + choose);
            tickets_list.erase(tickets_list.begin() + choose);
            cout << "flight is deleted :)" << endl;
        }
        
    }
    
    
}

void delete_from_mashins(vector<mashin_hamle_bar> & mashins_list)
{
    int choose = -1;
    char taaid;
    for (size_t i = 0; i < mashins_list.size(); i++)
    {
        cout << i+1 << ")\t";
        mashins_list[i].print_info();
    }

    cout << "enter number of pilot you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= mashins_list.size())
    {
        cout << "do you want to delete this pilot?" << endl;
        mashins_list[choose - 1].print_info();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            mashins_list.erase(mashins_list.begin() + choose);
            cout << "pilot is deleted :)" << endl;
        }
        
    }
    
    
}

void delete_from_tickets(vector<vector<ticket>> & tickets_list , vector<flight> & flights_list)
{
    int choose = -1;
    int find = -1;
    char taaid;
    string f_code;

    cout << "**********************************************" << endl;
    cout << "flight codes : " << endl;
    for (size_t i = 0; i < flights_list.size(); i++)
    {
        cout << flights_list[i].return_flight_code() << endl;
    }
    cout << "**********************************************" << endl;
    cout << "enter flight code : ";
    cin >> f_code;

    for (size_t i = 0; i <  flights_list.size(); i++)
    {
        if (f_code == flights_list[i].return_flight_code())
        {
            find == -1;
            break;
        }
    }
    
    

    for (size_t i = 0; i < tickets_list.size(); i++)
    {
        cout << i+1 << ")\t";
        tickets_list[find][i].print_info();
    }

    cout << "enter number of ticket you want to delete -> ";
    cin >> choose;

    if (choose > 0 && choose <= tickets_list.size())
    {
        cout << "do you want to delete this ticket?" << endl;
        tickets_list[find][choose - 1].print_info();
        cout << "YES : Y" << endl << "NO : N" << endl;
        cin >> taaid;
        if (taaid == 'Y' || taaid == 'y')
        {
            tickets_list.erase(tickets_list.begin() + choose);
            cout << "ticket is deleted :)" << endl;
        }
        
    }  
}