#include <iostream>
#include <string>
using namespace std;
class Worker {
private:
    string Worker_Name;
    int No_Of_Hours_Worked;
    double Pay_Rate;
    double Salary;
public:
    Worker(string name, int hours, double pay_rate = 500)
        : Worker_Name(name), No_Of_Hours_Worked(hours), Pay_Rate(pay_rate) {
        calculateSalary(); 
    }
    void calculateSalary() {
        Salary = No_Of_Hours_Worked * Pay_Rate;
    }
    void displayInfo() const {
        cout << "Worker Name: " << Worker_Name << endl;
        cout << "Hours Worked: " << No_Of_Hours_Worked << endl;
        cout << "Pay Rate: Rs. " << Pay_Rate << " per hour" << endl;
        cout << "Total Salary: Rs. " << Salary << endl;
    }
};
int main() {
    string name;
    int hours;
    cout << "Enter Worker Name: ";
    getline(cin, name);
    cout << "Enter Number of Hours Worked: ";
    cin >> hours;
    Worker worker(name, hours);
    worker.displayInfo();
    return 0;
}
