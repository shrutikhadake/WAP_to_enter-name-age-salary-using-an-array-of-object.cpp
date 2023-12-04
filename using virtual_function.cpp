//using virtual function 
#include <iostream>

class Person {
protected:
    string name;
    int age;

public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    virtual void display() = 0;
};

class Employee : public Person {
private:
    float salary;

public:
    void setSalary(float salary) {
        this->salary = salary;
    }

    float getSalary() {
        return salary;
    }

    virtual void display() override {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

int main() {
    Employee employees[5];

    for (int i = 0; i < 5; i++) {
        string name;
        int age;
        float salary;

        cout << "Enter name for employee " << i + 1 << ": ";
        cin >> name;

        cout << "Enter age for employee " << i + 1 << ": ";
        cin >> age;

        cout << "Enter salary for employee " << i + 1 << ": ";
        cin >> salary;

        employees[i] = Employee();
        employees[i].setName(name);
        employees[i].setAge(age);
        employees[i].setSalary(salary);
    }

    cout << endl << "Employee Information:" << endl;

    for (int i = 0; i < 5; i++) {
        employees[i].display();
        cout << endl;
    }

    return 0;
}
