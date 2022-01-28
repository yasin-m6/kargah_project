#include <iostream>
#include "peaple.hpp"

using namespace std;


peaple::peaple(string f_name , string l_name , string n_code , string birth_d)
{
    while (1)
    {
        try
        {
            set_first_name(f_name);
            break;
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
            f_name = get_info("first name");
            fflush(stdin);
        }   
    }

    while (1)
    {
        try
        {
            set_last_name(l_name);
            break;
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
            l_name = get_info("last name");
            fflush(stdin);
        }   
    }

    while (1)
    {
        try
        {
            set_national_code(n_code);
            break;
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
            n_code = get_info("national code");
            fflush(stdin);
        }   
    }

    while (1)
    {
        try
        {
            set_birth_day(birth_d);
            break;
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
            birth_d = get_birth();
        }   
    }
    
}


peaple::~peaple()
{

}

string peaple::get_info(string type) const
{
    string info;

    cout << "Enter your " << type << " : ";
    cin >> info;

    return info;
}

void peaple::set_first_name(string first_name)
{
    for (size_t i = 0; i < first_name.size() ; i++)
    {
        if(isalpha(first_name[i]) != isalpha('a') && isalpha(first_name[i]) != isalpha('A') )
        {
            throw invalid_argument("first name has to be contain by alphabets !!!!!");
        }
    }

    for (size_t i = 0; i < first_name.size() ; i++)
    {
        if(i == 0)
        {
            first_name[i] = toupper(first_name[i]);
        }
        else
        {
            first_name[i] = tolower(first_name[i]);
        }
    }
    
    this->first_name = first_name;
}


void peaple::set_last_name(string last_name)
{
    for (size_t i = 0; i < last_name.size() ; i++)
    {
        if(isalpha(last_name[i]) != isalpha('a') && isalpha(last_name[i]) != isalpha('A') )
        {
            throw invalid_argument("last name has to be contain by alphabets !!!!!");
        }
    }

    for (size_t i = 0; i < last_name.size() ; i++)
    {
        if(i == 0)
        {
            last_name[i] = toupper(last_name[i]);
        }
        else
        {
            last_name[i] = tolower(last_name[i]);
        }
    }
    
    this->last_name = last_name;
}


void peaple::set_national_code(string national_code)
{
    for (size_t i = 0; i < national_code.size() ; i++)
    {
        if(isdigit(national_code[i]) != isdigit('1') )
        {
            throw invalid_argument("national_code has to be contain by digits !!!!!");
        }
    }

    
    
    this->national_code = national_code;
}


string peaple::get_birth() const
{
    string birth_d;

    cout << "birth day is contain by 2 digits for day and month and 4 digits for year" << endl;
    cout << "put a space between each of them" << endl;
    cout << "Enter yor birth day : ";
   // cin >> birth_d.day >> birth_d.month >> birth_d.year;

    

    return birth_d;
}

void peaple::set_birth_day(string birth_day)
{
    

    this->birth_day = birth_day;
    
}