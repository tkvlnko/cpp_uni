#include <iostream>

class Person
{
    std::string name;

public:
    Person(const std::string&);
    virtual void print() const;
};

Person::Person(const std::string& name)
{
    this->name = name;
}

void Person::print() const
{
    std::cout << this->name << '\n';
}

class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(const std::string&, double);
    void print() const;
};

Teacher::Teacher(const std::string& name, double salary) : Person(name), salary(salary)
{
}

void Teacher::print() const
{
    Person::print();
    std::cout << this->salary << '\n';
};

class Student : public Person
{
private:
    int rating;

public:
    Student(const std::string&, int);
    void print() const;
};

Student::Student(const std::string& name, int rating) : Person(name), rating(rating){};


void Student::print() const
{
    Person::print();
    std::cout << this->rating << '\n';
};


class Assistant : public Student, public Teacher
{

public:
    Assistant(const std::string&, double, int);
    void print() const;
};

Assistant::Assistant(const std::string& name, double salary, int rating) : Teacher(name, salary), Student(name, rating)
{}


void Assistant::print() const
{
    Teacher::print();
    Student::print();
};


int main()
{
    Person ivan{"ivan"};
    Teacher petro{"petro", 1000000};
    Student ivan2{"ivan2", 1};

    ivan2.print();
}