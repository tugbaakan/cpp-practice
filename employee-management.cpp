#include <iostream>
#include <vector>
#include <string>
#include "employee.h"

using namespace std;

void createEmployee(int _employeeIdCounter, vector<Employee>& employeeList) {

    string name;
    while (true)
    {
        string userInput;
        cout << "Enter the name of the employee:" << endl;
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, userInput);

        if (!userInput.empty())
        {
            name = userInput;
            break;
        }
    }

    string title;
    while (true)
    {
        string userInputTitle;
        cout << "Enter the title of the employee:" << endl;
  //      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, userInputTitle);

        if (!userInputTitle.empty())
        {
            title = userInputTitle;
            break;
        }
    }

    cout << "kullanici bilgileri basariyla girildi";

    employeeList.emplace_back(_employeeIdCounter, name, title);

}

void listEmployees(const vector<Employee>& employees) {

    for (const auto& emp : employees) {
        emp.print();
    }
}

void searchEmployee(const vector<Employee>& employees) {
    string userInput;
    cout << "enter the name of the employee that you want to search:";
    cin >> userInput;
    cout << "searching employees" << endl;
    int sayac = 0;
    for (const auto& emp : employees)
    {
        string name = emp.getName();
        if (name.find(userInput) != std::string::npos)
        {
            sayac++;
            emp.print();
        }
    }

    if (sayac == 0)
    {
        cout << "no employee found" << endl;
    }

}

void deleteEmployee(vector<Employee>& employees) {
    string userInput;
    int employeeId;

    while (true)
    {
        cout << "enter the id of the employee that you want to delete" << endl;
        cin >> userInput;

        try {
            size_t processedChars = 0;
            employeeId = stoi(userInput, &processedChars);

            // Ensure the entire input was numeric (e.g., rejects "123abc")
            if (processedChars == userInput.length()) {
                break; // Valid conversion, exit loop
            }
            cout << "Invalid input. Please enter numbers only." << endl;
        }
        catch (const invalid_argument&) {
            cout << "Invalid input! Please enter a valid number." << endl;
        }
        catch (const out_of_range&) {
            cout << "Number is too large or too small!" << endl;
        }
    }

    for (auto it = employees.begin(); it != employees.end(); it++)
    {
        if (it->getEmployeeId() == employeeId) {
            employees.erase(it);
            cout << "Deleted employee with ID: " << employeeId << endl;
            return;
        }
    }

}

int main() {

    vector<Employee> vcEmployees;

    string userInput = "1";
    int employeeIdCounter = 0;

    while (userInput != "5")
    {

        cout << "-------Personel yonetim sistemi----------" << endl;
        cout << "1. Personel Ekle" << endl;
        cout << "2. Personel listele" << endl;
        cout << "3. Personel Ara" << endl;
        cout << "4. Personel Sil" << endl;
        cout << "5. Cikis" << endl;
        cout << "Seciminizi yapiniz:" << endl;

        cin >> userInput;

        if (userInput == "1")
        {
            employeeIdCounter++;
            createEmployee(employeeIdCounter, vcEmployees);
        }
        else if (userInput == "2")
        {
            listEmployees(vcEmployees);
        }
        else if (userInput == "3")
        {
            searchEmployee(vcEmployees);
        }
        else if (userInput == "4")
        {
            deleteEmployee(vcEmployees);
        }
        else if (userInput != "5")
        {
            cout << "yanlis tuslama yaptiniz lutfen 1 ve 5 arasinda bir sayı giriniz:";
        }
        else
            continue;

    }

    return 0;
}