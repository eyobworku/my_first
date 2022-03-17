#include<iostream>
#include<sstream>
#include"TextTable.h"  //header file used to show the data in Table source: https://github.com/haarcuba/cpp-text-table
using namespace std;

float calInTax(float);
float calNetIn(float);
float calPension(float);
int incScale(float);
void listData();
void addEmplo();
void menu();
void wait();
void showTable();
string Convert(float);

const float taxRate[7] = {0,0.1,0.15,0.2,0.25,0.3,0.35};  //tax rate index by income scale
const float deduction[7] = {0,60,142.50,302.50,565,955,1500};

struct employee
{
    string name;
    float salary;
    //float bonus;
};

struct employeeInfo{
    float incomeTax;
    float pension;
    float netIncome;
};

employee employeeData[10]; // employe data holder entered by the user
employeeInfo employeeCalInf[10]; // employee calculated information
int noEmplo=0; //number of employee used to track the data entered by the user

int main(){
    menu();
    
    return 0;
}

float calInTax(float salary){
    int scale = incScale(salary);
    float incomeTax = (salary * taxRate[scale]) - deduction[scale];
    return incomeTax;
}

float calPension(float salary){
    return salary * 0.07;
}

float calNetIn(float salary){
    return salary - calInTax(salary) - calPension(salary);
}

int incScale(float salary){
    int scale;
    if(salary > 0 && salary <= 600)
        scale = 0;
    else if(salary > 600 && salary <= 1650)
        scale = 1;
    else if(salary > 1650 && salary <= 3200)
        scale = 2;
    else if(salary > 3200 && salary <= 5250)
        scale = 3;
    else if(salary > 5250 && salary <= 7800)
        scale = 4;
    else if(salary > 7800 && salary <= 10900)
        scale = 5;
    else if(salary > 10900)
        scale = 6;
    return scale;
}

void addEmplo(){
    cout << "Enter your employee"<< noEmplo+1 <<" name: ";
    cin.ignore('\n',10);
    getline(cin,employeeData[noEmplo].name,'\n');
    cout << "Enter your employee"<< noEmplo+1 <<" salary: ";
    cin >> employeeData[noEmplo].salary;
    // cout << "Enter your employee"<< noEmplo+1 <<" bonus: ";
    // cin >> employeeData[noEmplo].bonus;
    employeeCalInf[noEmplo].incomeTax = calInTax(employeeData[noEmplo].salary);  //calculate user information
    employeeCalInf[noEmplo].pension = calPension(employeeData[noEmplo].salary);
    employeeCalInf[noEmplo].netIncome = calNetIn(employeeData[noEmplo].salary);

    noEmplo++; // add 1 to the next index in employee data array
}

void menu(){
    int menuIndex;
    bool waited = true;
    cout << "Payroll Management System :)"<<endl;
    cout << "1. Add employee."<<endl;
    cout << "2. List employee data."<<endl;
    cout << "0. Exit"<<endl;
    cout << "Please enter your choice: ";
    cin >> menuIndex;
    switch (menuIndex)
    {
    case 1:
        addEmplo();
        break;
    case 2:
        showTable();
        waited = false;
        wait();
        break;
    case 0:
        exit(0);
        break;
    default:
        system("cls");
        cout << "Please choose from the above"<< endl;
        menu();
    }
    if (waited){
        wait();
    }
    menu();
}

void wait(){
    cout << "(please enter to continue or press any key to exit)";
    cin.ignore(100,'\n');
    if (cin.get() == '\n') {
        system("cls");
    }
    else{
        exit(0);
    }
}

void showTable(){
    TextTable t( '-', '|', '+' );

    t.add( "Name" );
    t.add( "Salary" );
    t.add( "Income Tax" );
    t.add( "Pension" );
    t.add( "Net salary" );
    t.endOfRow();

    for (int i = 0; i < noEmplo; i++)
    {
        t.add(employeeData[i].name);
        t.add(Convert(employeeData[i].salary));
        t.add(Convert(employeeCalInf[i].incomeTax));
        t.add(Convert(employeeCalInf[i].pension));
        t.add(Convert(employeeCalInf[i].netIncome));
        t.endOfRow();   
    }

    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << t;
}
 //Function to convert float to string
string Convert(float number){
    ostringstream buff;
    buff<<fixed<<setprecision(2)<<number;//setting the precision to two
    return buff.str();//converting to string
}