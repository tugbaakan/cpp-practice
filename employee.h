#pragma once
#include <iostream>

using namespace std;

class Employee {
private:
    int employeeId;
    string name;
    string title;

public:
    Employee(int _employeeId, string _name, string _title) {
        employeeId = _employeeId;
        name = _name;
        title = _title;
    }

    void print() const {
        cout << employeeId << " " << name << " " << title << endl;
    }

    int getEmployeeId() const {
        return employeeId;
    }

    string getName() const {
        return name;
    }

    string getTitle() const {
        return title;
    }

};


