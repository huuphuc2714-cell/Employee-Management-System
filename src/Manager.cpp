#include "../include/Manager.h"
#include <string>
#include<iostream>

using namespace std;

// =====CONSTRUCTOR=====

Manager::Manager() : Employee(){
    teamSize = 0 ;
}
Manager::Manager(string id, string fullname, string Dob, string phone_number, double baseSalary, int teamSize)
: Employee(id, fullname, Dob, phone_number, baseSalary, Position::MANAGER){
    this->teamSize = teamSize ; 
}

// =====GETTER/SETTER=====

int Manager::getTeamSize() const{
    return teamSize ;
}
void Manager::setTeamSize(int teamSize){
    this->teamSize = teamSize ;
}

// =====CÁC PHƯƠNG THỨC KHÁC=====

double Manager::calculateSalary(){
    return baseSalary + teamSize * MANAGEMENT_ALLOWANCE ;
}

void Manager::displayInfo(){
    cout << "===== MANAGER =====" << endl ;
    Employee::displayInfo() ;
    cout << "Team Size: " << teamSize << endl ;
}
