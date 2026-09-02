#pragma once
#include <string>

enum class Position{MANAGER, FULLTIME, PARTTIME} ;

class Employee{
protected: 
    std::string id ;
    std::string fullname ; 
    std::string Dob ; // d/m/y 
    std::string phone_number ;
    double baseSalary ;
    Position pos ; // M F P 
public:
    Employee();
    Employee(std::string id, std::string fullname, std::string Dob, std::string phone_number, double baseSalary, Position pos) ;
    virtual ~Employee() = default;

    void setID(std::string id) ;
    void setFullName(std::string fullname) ;
    void setDob(std::string Dob) ;
    void setPhoneNumber(std::string phone_number) ;
    void setBaseSalary(double baseSalary) ;
    void setPos(Position pos) ;

    std::string getID() const ;
    std::string getFullName() const ;
    std::string getDob() const ;
    std::string getPhoneNumber() const ;
    double getBaseSalary() const ;
    std::string getPos() const ;

    virtual double calculateSalary() = 0 ;
    virtual void displayInfo() ;
};