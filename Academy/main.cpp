#include "stdafx.h"
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"
#include"Functions.h"

//#define INHERITANCE_CHECK
//#define POLYMORPHISM
#define LOAD_FROM_FILE
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
        new Teacher("Diaz", "Ricardo", 50, "Weapons distribution",25),
        new Graduate("Rosenberg", "Ken", 27, "Layer","Vice", 75,20,"Get moneybag")
    };
    //Specialization
    print(group, sizeof(group) / sizeof(group[0]));
    save(group, sizeof(group) / sizeof(group[0]), "group.txt");

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        delete group[i];
    }
#endif // POLYMORPHISM

#ifdef LOAD_FROM_FILE
    int n=0;      //Размер группы
    Human** group = load("group.txt", n);
    print(group,n);
    for (int i = 0; i < n; i++)
    {
        delete group[i];
    }
    delete[] group;
    group = nullptr;
#endif // LOAD_FROM_FILE
}