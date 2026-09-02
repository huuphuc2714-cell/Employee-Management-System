#include "../include/Employee.h"
#include <iostream>

using namespace std;

// =====CONSTRUCTOR=====

Employee::Employee(){
    id = "default" ;
    fullname = "default" ;
    Dob = "0/0/0" ; 
    phone_number = "0000000000" ;
    baseSalary = 0 ;
    pos = Position::MANAGER ;
}
Employee::Employee(string id, string fullname, string Dob, string phone_number, double baseSalary, Position pos){
    this->id = id ;
    this->fullname = fullname ;
    this->Dob = Dob ;
    this->phone_number = phone_number ;
    this->baseSalary = baseSalary ;
    this->pos = pos ;
}

// =====SETTER=====

void Employee::setID(string id){
    this->id = id ;
} 
void Employee::setFullName(string fullname){
    this->fullname = fullname ;
}
void Employee::setDob(string Dob){
    this->Dob = Dob ;
}
void Employee::setPhoneNumber(string phone_number){
    this->phone_number = phone_number ;
}
void Employee::setBaseSalary(double baseSalary){
    this->baseSalary = baseSalary ;
}
void Employee::setPos(Position pos){
    this->pos = pos ;
}

// =====GETTER=====

string Employee::getID() const{
    return id ;
}
string Employee::getFullName() const{
    return fullname ;
}
string Employee::getDob() const{
    return Dob ;
}
string Employee::getPhoneNumber() const{
    return phone_number ;
}
double Employee::getBaseSalary() const{
    return baseSalary ;
}
string Employee::getPos() const{
    if(pos == Position::MANAGER){
        return "Manager" ;
    }else if(pos == Position::FULLTIME){
        return "FullTime" ;
    }else if(pos == Position::PARTTIME){
        return "PartTime" ;
    }else{
        return "Default" ;
    }
}

// =====CÁC PHƯƠNG THỨC KHÁC=====

void Employee::displayInfo(){
    cout << "ID: " << id << endl ; 
    cout << "Full Name: " << fullname << endl ;
    cout << "Dob: " << Dob << endl ;
    cout << "Phone Number: " << phone_number << endl ;
}