#ifndef PEAPLE
#define PEAPLE

    #include <string>


    struct DAY
    {
        int day;
        int month;
        int year;
    };
    

    class peaple
    {
        public:
            peaple(std::string , std::string , std::string , std::string);
            ~peaple();
            std::string get_info(std::string) const;
            std::string get_birth() const;
            void set_first_name(std::string);
            void set_last_name(std::string);
            void set_national_code(std::string);
            void set_birth_day(std::string);
        protected:
            std::string first_name;
            std::string last_name;
            std::string birth_day;
            std::string national_code;
    };

#endif