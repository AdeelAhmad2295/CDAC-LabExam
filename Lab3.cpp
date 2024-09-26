#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
class Employee {
public:
    int EmpId;
    string Name;
    double Salary;

    Employee(int id, const string& name, double salary)
        : EmpId(id), Name(name), Salary(salary) {}
};
void printAllEmployees(const vector<Employee>& employees) {
    cout << "List of Employees:\n";
    for (const auto& emp : employees) {
        cout << "EmpId: " << emp.EmpId 
                  << ", Name: " << emp.Name 
                  << ", Salary: " << emp.Salary << '\n';
    }
}
void printHighestSalaryEmployee(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No employees to display.\n";
        return;
    }
    double highestSalary = numeric_limits<double>::min();
    Employee highestPaid = employees[0];
    for (const auto& emp : employees) {
        if (emp.Salary > highestSalary) {
            highestSalary = emp.Salary;
            highestPaid = emp;
        }
    }
    cout << "Employee with Highest Salary:\n"
              << "EmpId: " << highestPaid.EmpId 
              << ", Name: " << highestPaid.Name 
              << ", Salary: " << highestPaid.Salary << '\n';
}
int main() {
    vector<Employee> employees;
    for (int i = 0; i < 2; ++i) {
        int id;
        string name;
        double salary;

        cout << "Enter details for Employee " << (i + 1) << ":\n";
        cout << "EmpId: ";
        cin >> id;
        cin.ignore();  
        cout << "Name: ";
        getline(cin, name);
        cout << "Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, salary);
    }
    printAllEmployees(employees);
    printHighestSalaryEmployee(employees);

    return 0;
}
