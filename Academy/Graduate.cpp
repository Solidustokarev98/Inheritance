#include"Graduate.h"

    const std::string& Graduate::get_subject()const
    {
        return subject;
    }
    void Graduate::set_subject(const std::string& subject)
    {
        this->subject = subject;
    }
    //Constructors
    Graduate::Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
    {
        this->subject = subject;
        cout << "GConstructor:\t" << this << endl;
    }
    Graduate::~Graduate()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    std::ostream& Graduate::print(std::ostream& os)const
    {
        return Student::print(os) << " " << subject;
    }
    std::ofstream& Graduate::print(std::ofstream& ofs)const
    {
        Student::print(ofs);
        ofs << subject;
        return ofs;
    }
    std::ifstream& Graduate::scan(std::ifstream& ifs)
    {
        Student::scan(ifs);
        std::getline(ifs, subject);
        return ifs;
    }