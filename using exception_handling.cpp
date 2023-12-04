//using exception handling

#include <iostream>
#include <exception>

using namespace std;

class InvalidInputException : public exception {
public:
    InvalidInputException(const string& message) : message(message) {}

    const string& getMessage() const {
        return message;
    }

private:
    string message;
};

class Employee {
private:
    string name;
    int age;
    float salary;

public:
    Employee(string name, int age, float salary) {
        if (name.empty()) {
            throw InvalidInputException("Invalid input: Name cannot be empty");
        }

        if (age <= 0) {
            throw InvalidInputException("Invalid input: Age must be positive");
        }

        if (salary < 0.0f) {
            throw InvalidInputException("Invalid input: Salary must be non-negative");
        }

        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    try {
        Employee employees[5];

        for (int i = 0; i < 5; i++) {
            string name;
            int age;
            float salary;

            cout << "Enter name for employee " << i + 1 << ": ";
            getline(cin, name);

            cout << "Enter age for employee " << i + 1 << ": ";
            cin >> age;

            cout << "Enter salary for employee " << i + 1 << ": ";
            cin >> salary;

            employees[i] = Employee(name, age, salary);
        }

        cout << endl << "Employee Information:" << endl;

        for (int i = 0; i < 5; i++) {
            employees[i].display();
            cout << endl;
        }
    } catch (InvalidInputException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}
