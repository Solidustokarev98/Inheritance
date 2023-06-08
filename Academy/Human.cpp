#include"Human.h"


    const std::string& Human::get_last_name()const
    {
        return last_name;
    }
    const std::string& Human::get_first_name()const
    {
        return first_name;
    }
    int Human::get_age()const
    {
        return age;
    }
    void Human::set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    }
    void Human::set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }
    void Human::set_age(int age)
    {
        this->age = age;
    }
    //Constructors
    Human::Human(HUMAN_TAKE_PARAMETERS)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_age(age);
        cout << "HConstructor:\t" << this << endl;
    }
    virtual Human::~Human()
    {
        cout << "HDestructor:\t" << this << endl;
    }
    virtual std::ostream& Human::print(std::ostream& os)const
    {
        return os << last_name << " " << first_name << " " << age << " y/o";
    }
    virtual ofstream& Human::print(std::ofstream& ofs)const
    {
        ofs.width(LAST_NAME_WIDTH);
        ofs << std::left;
        ofs << last_name;
        ofs.width(FIRST_NAME_WIDTH);
        ofs << first_name;
        ofs.width(3);
        ofs << age;
        return ofs;
    }
    virtual std::ifstream& Human::scan(std::ifstream& ifs)
    {
        ifs >> last_name >> first_name >> age;
        return ifs;
    }
};