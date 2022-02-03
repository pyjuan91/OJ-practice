#include <iostream>
using namespace std;
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};
class Employee : AbstractEmployee
{
protected:
    string Name;
    string Company;
    int Age;

public:
    void introduce()
    {
        cout << "Name: " << Name << endl;
        cout << "Comany: " << Company << endl;
        cout << "Age: " << Age << endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    Employee()
    {
        Name = "";
        Company = "";
        Age = -1;
    }
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }
    void AskForPromotion()
    {
        if (Age > 30)
        {
            cout << Name << " got promoted!" << endl;
        }
        else
        {
            cout << Name << ", sorry NO promotion for you!" << endl;
        }
    }
};
class Developer : public Employee
{
public:
    string Editor;
    Developer(string name, string company, int age, string editor)
        : Employee(name, company, age)
    {
        Editor = editor;
    }
    void printName()
    {
        cout << Name << endl;
    }
};
class Teacher :public Employee
{
public:
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    }
    string Subject;
    void preparelesson()
    {
        cout << Name << "is preparing " << Subject << " lesson\n";
    }
    void AskForPromotion()
    {
        if (Age >= 20)
            cout << "yes\n";
        else
            cout << "no\n";
    }
};
int main(void)
{
    Teacher t("k", "nthu", 20, "c++");
    // t.preparelesson();
    // t.AskForPromotion();
    Employee *a = &t;
    a->AskForPromotion();
    return 0;
}