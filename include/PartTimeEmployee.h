#pragma once
#include "Employee.h"
#include <string>

class PartTimeEmployee : public Employee{
private: 
    int workingHours ; // số giờ làm việc trong 1 tuần 
    const int PAYMENTPERHOUR = 35 ;
public: 
    PartTimeEmployee() ;
    PartTimeEmployee(std::string id, std::string fullname, std::string Dob, std::string phone_number) ;

    void setWorkingHours(int workingHours) ;
    int getWorkingHours() const ;

    double calculateSalary() ;
    void displayInfo() ;
};

