#pragma once
#include "Employee.h"
#include <string>

class FullTimeEmployee : public Employee{
private: 
    double bonusRate ;
public: 
    FullTimeEmployee() ;
    FullTimeEmployee(std::string id, std::string fullname, std::string Dob, std::string phone_number, double baseSalary, double bonusRate) ;

    void setBonusRate(double bonusRate) ;
    double getBonusRate() const ;

    double calculateSalary() ;
    void displayInfo() ;
};

