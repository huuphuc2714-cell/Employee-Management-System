#include "../include/FullTimeEmployee.h"
#include <string>
#include <iostream>

using namespace std; 

FullTimeEmployee::FullTimeEmployee() : Employee(){
    bonusRate = 0 ;
}
FullTimeEmployee::FullTimeEmployee(string id, string fullname, string Dob, string phone_number, double baseSalary, double bonusRate)
: Employee(id, fullname, Dob, phone_number, baseSalary, Position::FULLTIME){
    this->bonusRate = bonusRate ;
}

void FullTimeEmployee::setBonusRate(double bonusRate){
    this->bonusRate = bonusRate ;
}
double FullTimeEmployee::getBonusRate() const{
    return bonusRate ;
}

double FullTimeEmployee::calculateSalary(){
    return baseSalary + (baseSalary * bonusRate) ;
}
void FullTimeEmployee::displayInfo(){
    cout << "===== Full Time Employee =====" << endl ;
    Employee::displayInfo() ;
    cout << "Bonus Rate: " << bonusRate << endl ;
}


