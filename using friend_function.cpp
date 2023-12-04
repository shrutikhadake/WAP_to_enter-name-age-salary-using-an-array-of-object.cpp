//using friend function
#include <iostream>

class Employee {
private:
    string name;
    int age;
    float salary;

friend void enterEmployeeDetails(Employee& employee);
friend void displayEmployeeDetails(const Employee& employee);

public:
    Employee() {}
};

void enterEmployeeDetails(Employee& employee) {
    cout << "Enter name: ";
    cin >> employee.name;

    cout << "Enter age: ";
    cin >> employee.age;

    cout << "Enter salary: ";
    cin >> employee.salary;
}

void displayEmployeeDetails(const Employee& employee) {
    cout << "Name: " << employee.name << endl;
    cout << "Age: " << employee.age << endl;
    cout << "Salary: " << employee.salary << endl;
}

int main() {
    Employee employees[5];

    for (int i = 0; i < 5; i++) {
        enterEmployeeDetails(employees[i]);
    }

    cout << endl << "Employee Information:" << endl;

    for (int i = 0; i < 5; i++) {
        displayEmployeeDetails(employees[i]);
        cout << endl;
    }

    return 0;
}
