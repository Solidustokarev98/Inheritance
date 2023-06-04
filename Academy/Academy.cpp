#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------\n"
#define human_take_parameters const std::string& last_name, const std::string& first_name, int age
#define human_give_parameters last_name, first_name, age
class Human
{
    std::string last_name;
    std::string first_name;
    int age;
public:
    const std::string& get_last_name()const
    {
        return last_name;
    }
    const std::string& get_first_name()const
    {
        return first_name;
    }
    int get_age()const
    {
        return age;
    }
    void set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    } 
    void set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }
    void set_age(int age)
    {
        this->age = age;
    }
        //Constructors
    Human(human_take_parameters)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_age(age);
        cout << "HConstructor:\t" << this << endl;
    }
    ~Human()
    {
        cout << "HDestructor:\t" << this << endl;
    }

    virtual void print()const
    {
        cout << last_name << " " << first_name << " " << age << " y/o"<<endl;
    }

};
std::ostream& operator<<(std::ostream & os, const Human & obj)
{
    return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
}

#define student_take_parameters const std::string& speciality, const std::string& group, double rating, double attendance
#define student_give_parameters speciality, group, rating, attendance
class Student :public Human
{
    std::string speciality;
    std::string group;
    double rating;
    double attendance;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    const std::string& get_group()const
    {
        return group;
    }
    double get_rating()const
    {
        return rating;
    }
    double get_attendance()
    {
        return attendance;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality=speciality;
    }
    void set_group(const std::string& group)
    {
        this->group=group;
    }
    void set_rating(double rating)
    {
        this->rating=rating;
    }
    void set_attendance(double attendance)
    {
        this->attendance=attendance;
    }
    //Constructors
    Student(human_take_parameters, student_take_parameters):Human(human_give_parameters)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);
        cout << "SConstructor:\t" << this << endl;
    }
    ~Student()
    {
        cout << "SDestructor:\t" << this << endl;
    }

    void print()const
    {
        Human::print();
        cout << speciality << ", " << group << " " << rating << " " << attendance<< endl;
    }
};

#define Teacher_take_parameters const std::string& speciality, int experienrce
#define Teacher_give_parameters speciality, experienrce
class Teacher :public Human
{
    std::string speciality;
    int experienrce;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    int get_experience()const
    {
        return experienrce;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_experience(int experienrce)
    {
        this->experienrce= experienrce;
    }
    //Constructors
    Teacher(human_take_parameters,Teacher_take_parameters):Human(human_give_parameters)
    {
        set_speciality(speciality);
        set_experience(experienrce);
        cout << "TConstructor:\t" << this << endl;
    }
    ~Teacher()
    {
        cout << "TDestructor:\t" << this << endl;
    }

    void print()const
    {
        Human::print();
        cout << speciality << " " << experienrce << endl;
    }
};

class Graduate: public Student
{
    std::string subject;
public:
    const std::string& get_subject()const
    {
        return subject;
    }
    void set_subject(const std::string& subject)
    {
        this->subject = subject;
    }
    //Constructors
    Graduate(human_take_parameters,student_take_parameters,const std::string& subject):Student(human_give_parameters,student_give_parameters)
    {
        this->subject = subject;
        cout << "GConstructor:\t" << this << endl;
    }
    ~Graduate()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    void print()const
    {
        Student::print();
        cout << subject << endl;
    }
};
void print(Human** group,const int n)
{
    cout << delimiter << endl;
    for (int i = 0; i < n; i++)
    {
        //group[i]->print();
        cout << group[i];
        cout << delimiter << endl;
    }
 }

void save(Human** group, const int n,const char* filename)
{
    ofstream fout(filename);
    fout << delimiter << endl;
    for (int i = 0; i < n; i++)
    {
        fout << *group[i] << endl;
        fout << delimiter << endl;
    }
    fout.close();
    char command[FILENAME_MAX] = "notepad ";
    strcat(command, filename);
    system(command);
}

//#define INHERITANCE_CHECK
#define POLYMORPHISM
void main()
{
    setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
    Human human("Vercetty", "Tomas", 30);
    human.print();

    Student student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95);
    student.print();

    Teacher teacher("White", "Walter", 50, "Chemistry", 20);
    teacher.print();

    Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg");
    graduate.print();
#endif // INHERITANCE_CHECK

#ifdef POLYMORPHISM
    //Многоформенность (poly - много, morphis - форма)
    //Generalization
    Human* group[]
    {
        new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95),
        new Teacher("White", "Walter", 50, "Chemistry", 20),
        new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg"),
        new Student("Vercetty", "Tomas", 30, "Theft", "Vice", 98,99),
        new Teacher("Diaz", "Ricardo", 50, "Weapons distribution",25)
    };
    //Specialization
    print(group, sizeof(group) / sizeof(group[0]));
    save(group, sizeof(group) / sizeof(group[0]), "group.txt");

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        delete group[i];
    }
#endif // POLYMORPHISM
}