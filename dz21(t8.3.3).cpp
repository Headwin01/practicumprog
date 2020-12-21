#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

vector<string> split(const string& s, char delimiter)
{   
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }

    return tokens;
}


class Person
{
protected:
    string name;
    unsigned int age;
public:
    Person() {}
    Person(string nm, unsigned int yr)
    {
        name = nm;
        age = yr;
    }

    void Print()
    {
        cout << "Name: " << name << ", " << "Age: " << age;
    }
};

class Student : public Person
{
private:
    unsigned int grade_five;
    unsigned int grade_hundred;

public:
    Student(string nm, unsigned int yr, unsigned int grade_fv, unsigned int grade_hun)
    {
        name = nm;
        age = yr;
        if (grade_fv <= 5) { grade_five = grade_fv; }
        else {cout << name << "Got wrong grade to 5" << endl;}
        if (grade_hun <= 100) {grade_hundred = grade_hun;}
        else {cout << name << "Got wrong grade to 100" << endl;}
    }

    unsigned int GetGradeFive()
    {
        return grade_five;
    }

    unsigned int GetGradeHundred()
    {
        return grade_hundred;
    }

    void Print()
    {
        Person::Print();
        cout << ", " <<  "Grade to 5: " << grade_five << ", " << "Grade to 100: " << grade_hundred << endl;
    }
};


vector<Student> OldScholarship(vector<Student>& stud)
{
    vector<Student> old_scholar;
    for(int i = 0; i < stud.size(); ++i)
    {
        if (stud[i].GetGradeFive() >= 4)
        {
            old_scholar.push_back(stud[i]);
        }
    }

    return old_scholar;
}

vector<Student> NewScholarship(vector<Student>& stud)
{
    vector<Student> new_scholar;

    int j;
    
    for(int i = 1; i < stud.size(); ++i)
    {
        Student key = stud[i];
        j = i - 1;

        while(j >= 0 && stud[j].GetGradeHundred() > key.GetGradeHundred())
        {
            stud[j + 1] = stud[j];
            j--;
        }
        stud[j + 1] = key;
    }

    int fourty_perc = stud.size() * 0.4;

    for(int i = stud.size() - fourty_perc; i < stud.size(); ++i)
    {
        new_scholar.push_back(stud[i]);
    }

    return new_scholar;
}


int main()
{
    vector<Student> students;

    fstream student_file("students.txt");

    while(student_file)
    {
        string line;
        getline(student_file, line);
        if (line != "")
        {   
            vector<string> temp = split(line, ' ');
            Student st(temp[0], stoi(temp[1]), stoi(temp[2]), stoi(temp[3]));
            students.push_back(st);
        }
        else { break; }
    }


    vector<Student> old_scholar = OldScholarship(students);

    for(int i = 0; i < old_scholar.size(); ++i)
    {
        old_scholar[i].Print();
    }


    vector<Student> new_scholar = NewScholarship(students);

    for(int i = 0; i < new_scholar.size(); ++i)
    {
        new_scholar[i].Print();
    }


    return 0;

}