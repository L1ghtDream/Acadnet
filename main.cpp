/*
    Acadnet 2017 - Etapa Interjudeteana
    Problema C - Jedi
*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
public:

    enum Gender {
        MALE,
        FEMALE
    };

    explicit Person(Gender t_gender, string t_name, int t_age);

    virtual void do_work() = 0;

    string m_name;
protected:
    Gender m_gender;
    int m_age;
};

Person::Person(Person::Gender t_gender, string t_name, int t_age):m_gender(t_gender), m_name(t_name), m_age(t_age) {}

class Profesor : public Person {
public:

    Profesor(Person::Gender t_gender, string t_name, int t_age);

    void add_student(Person* t_student);

    void do_work();
    void remove_student(Person* t_student);

private:
    map<string, Person*> m_students;
};

Profesor::Profesor(Person::Gender t_gender, string t_name, int t_age): Person(t_gender, t_name, t_age) {}

void Profesor::add_student(Person* t_student)
{
    m_students[t_student->m_name] = t_student;

    cout << this->m_name << " takes on " << t_student->m_name << " as a student.\n";
}

void Profesor::remove_student(Person* t_student)
{
    m_students.erase(t_student->m_name);

    cout << t_student->m_name << " is no longer a student of " << this->m_name << ".\n";
}

void Profesor::do_work()
{
    if (m_students.size() == 0)
    {
        cout << this->m_name << " has no students to teach.\n";
        return;
    }
    cout << this->m_name << " is teaching his student";
    if (m_students.size() > 1)
        cout << 's';

    bool first = true;
    for (map<string, Person*>::iterator it = m_students.begin(); it != m_students.end(); ++it)
    {
        if (first)
        {
            cout << ' ' << it->first;
            first = false;
        }
        else
            cout << ", " << it->first;
    }
    cout << ".\n";
}

class Student : public Person {
public:

    Student(Person::Gender t_gender, string t_name, int t_age, Profesor* t_profesor);
    ~Student();

    void do_work();

private:
    Profesor* m_profesor;
};

Student::Student(Person::Gender t_gender, string t_name, int t_age, Profesor* t_profesor): Person(t_gender, t_name, t_age)
{
    m_profesor=t_profesor;
    m_profesor->add_student(this);
}

Student::~Student()
{
    m_profesor->remove_student(this);
}

void Student::do_work()
{
    cout << this->m_name << " is learning by ";
    if (m_gender == Person::MALE)
        cout << "himself";
    else
        cout << "herself";
    cout << ".\n";
}

int main(int argc, char **argv)
{
    int flag;

    ifstream params;
    params.open("../params.txt");
    if(!params.good()) {
        cerr << "Failed to open params.txt file.\n";
        return -1;
    }

    params >> flag;

    Profesor yoda(Person::MALE, "Yoda", 900);
    if (flag % 2 == 0)
        yoda.do_work();

    Profesor obi(Person::MALE, "Obi-Wan Kenobi", 60);
    yoda.add_student(&obi);
    Profesor luke(Person::MALE, "Luke Skywalker", 40);
    yoda.add_student(&luke);
    if (flag % 3 == 0)
        yoda.do_work();

    yoda.remove_student(&obi);
    if (flag % 5 == 0)
        yoda.do_work();

    obi.add_student(&luke);

    Student rei (Person::FEMALE, "Rei", 20, &luke);
    if (flag % 7 == 0)
        rei.do_work();
    if (flag % 11 == 0)
        luke.do_work();

    params.close();

    return 0;
}
