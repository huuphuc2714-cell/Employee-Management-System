#pragma once
#include "Employee.h"
#include <string>

class Manager : public Employee{
private: 
    int teamSize ;
    const double MANAGEMENT_ALLOWANCE = 250 ;
public: 
    Manager() ;
    Manager(std::string id, std::string fullname, std::string Dob, std::string phone_number, double baseSalary, int teamSize) ;

    int getTeamSize() const; 
    void setTeamSize(int teamSize);

    double calculateSalary() ;
    void displayInfo() ;
};

