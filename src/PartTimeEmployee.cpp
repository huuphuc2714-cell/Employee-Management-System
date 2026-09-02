#include "../include/PartTimeEmployee.h"
#include <string>
#include <iostream> 

using namespace std; 

PartTimeEmployee::PartTimeEmployee() : Employee(){
    workingHours = 0 ;
}

PartTimeEmployee::PartTimeEmployee(string id, string fullname, string Dob, string phone_number) 
: Employee(id, fullname, Dob, phone_number, 0, Position::PARTTIME){
    
}

void PartTimeEmployee::setWorkingHours(int workingHours){
    this->workingHours = workingHours ;
}
int PartTimeEmployee::getWorkingHours() const{
    return workingHours ;
}

double PartTimeEmployee::calculateSalary(){
    return workingHours * PAYMENTPERHOUR * 4 ;
}
void PartTimeEmployee::displayInfo(){
    cout << "===== Part Time Employee =====" << endl ;
    Employee::displayInfo() ;
}