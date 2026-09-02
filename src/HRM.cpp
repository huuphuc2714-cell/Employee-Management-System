#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#include "../include/HRM.h"
#include "../include/Employee.h"
#include "../include/Manager.h"
#include "../include/FullTimeEmployee.h"
#include "../include/PartTimeEmployee.h"

using namespace std;

HRM::HRM(){

}

HRM::~HRM(){
    for(auto& emp : staffList){
        delete emp.second ;
    }
    staffList.clear() ;
    stafflist.clear() ;
}

static int getPosOrder(Employee* e){
    if(e->getPos() == "Manager") return 1 ;
    if(e->getPos() == "FullTime") return 2 ;
    return 3 ;
}

bool HRM::cmp(Employee* a, Employee* b){
    if(getPosOrder(a) != getPosOrder(b)){
        return getPosOrder(a) < getPosOrder(b) ;
    }
    if(a->getBaseSalary() != b->getBaseSalary()){
        return a->getBaseSalary() > b->getBaseSalary() ;
    }
    return a->getFullName() < b->getFullName() ;
}

void HRM::addEmployee(){  
    int choice ;
        cout << "===== CHON LOAI NHAN VIEN =====" << endl ; 
        cout << "1. Manager \n2. Full Time Employee \n3. Part Time Employee \n" ;
    while(true){
        cin >> choice ;
        if(choice == 1 || choice == 2 || choice == 3){
            break ;
        }else{
            cout << "Dau vao khong hop le !" << endl ;
        }
    }

    string id, name ; 
    string Dob, phone_number ; 
    cout << "Nhap ID: " ; cin >> id ; 
    cin.ignore() ;
    cout << "Nhap Ho va Ten: " ; 
    getline(cin, name) ;
    cout << "Nhap Dob: <d/m/y> Ex: 01/04/2007 " ; cin >> Dob ;
    cout << "Nhap sdt: " ; cin >> phone_number ;

    if(choice == 1){
        int baseslr ;
        cout << "Nhap muc luong co ban: " ;
        cin >> baseslr ;

        cout << "Nhap so nhan vien quan ly: " ; 
        int teamsize ;
        cin >> teamsize ;

        Employee* newMgr = new Manager(id, name, Dob, phone_number, baseslr, teamsize) ;
        staffList.insert({id, newMgr}) ;
        stafflist.push_back(newMgr) ;
        m ++ ;
        cout << "Da them Manager moi thanh cong" << endl ;
    }else if(choice == 2){
        int baseslr ;
        cout << "Nhap muc luong co ban: " ;
        cin >> baseslr ;

        double bonus ;
        cout << "Nhap he so thuong: " ;
        cin >> bonus ;

        Employee* newFTE = new FullTimeEmployee(id, name, Dob, phone_number, baseslr, bonus) ;
        staffList.insert({id, newFTE}) ; 
        stafflist.push_back(newFTE) ;
        f++ ;
        cout << "Da them nhan vien Full Time thanh cong" << endl ;
    }else{
        Employee* newPTE = new PartTimeEmployee(id, name, Dob, phone_number) ;
        staffList.insert({id, newPTE}) ; 
        stafflist.push_back(newPTE) ;
        p ++ ;
        cout << "Da them nhan vien Part Time thanh cong" << endl ;
    }

}

void HRM::displayListEmployees() const{
    cout << string(60,'-') << endl ;
    cout << left << setw(5) << "ID" << " | "
         << left << setw(10) << "Position" << " | "
         << left << setw(10) << "BirthDay" << " | "
         << left << setw(5) << "Phone Call" << " | "
         << "Full Name" << endl ;

    cout << string(60,'-') << endl ;
         
    for(auto& emp : stafflist){
        cout << left << setw(5) << emp->getID() 
             << " | " << left << setw(10) << emp->getPos() 
             << " | " << left << setw(10) << emp->getDob() 
             << " | " << left << setw(10) << emp->getPhoneNumber() 
             << " | " << left << setw(20) << emp->getFullName() << endl ;
    }
    cout << string(60,'-') << endl ;
}

void HRM::calculateTotalPayroll(){
    double totalSalary = 0 ;
    sortEmployees() ;
    cout << "===== Nhap luong nhan vien PartTime =====" << endl ;
    int wk ;
    for(auto& emp : stafflist){
        if(emp->getPos() == "PartTime"){
            PartTimeEmployee* pt = dynamic_cast<PartTimeEmployee*>(emp) ;
            if(pt == nullptr) continue ;
            cout << "Nhap so gio lam trong tuan cua nhan vien: " << pt->getID() << " | " << pt->getFullName() << ": " ;
            cin >> wk ;
            pt->setWorkingHours(wk) ;
            pt->calculateSalary() ;
        }
    }
    cout << endl << string(85,'-') << endl ;
    cout << "============================== Bang luong thang =============================" << endl ;

    cout << string(85,'-') << endl ;
    cout << left << setw(5) << "ID" << " | "
         << left << setw(10) << "Position" << " | "
         << left << setw(10) << "BirthDay" << " | "
         << left << setw(5) << "Phone Call" << " | "
         << left << setw(25) << "Full Name" << " | "
         << "Salary" << endl ;

    cout << string(85,'-') << endl ;

    for(int i = 0 ; i < f + m + p ; i ++){
        cout << left << setw(5) << stafflist[i]->getID() 
             << " | " << left << setw(10) << stafflist[i]->getPos() 
             << " | " << left << setw(10) << stafflist[i]->getDob() 
             << " | " << left << setw(10) << stafflist[i]->getPhoneNumber() 
             << " | " << left << setw(25) << stafflist[i]->getFullName() 
             << " | " << fixed << setprecision(0) << stafflist[i]->calculateSalary() << endl ;
        totalSalary += stafflist[i]->calculateSalary() ;
    }  
    cout << string(85,'-') << endl ;
    cout << "Total Salary: " << fixed << setprecision(0) << totalSalary << endl ;
    cout << string(85,'-') << endl ;
}

void HRM::searchEmployeeByID(string id) const{
    auto it = staffList.find(id) ;
    if(it != staffList.end()){
        it->second->displayInfo() ;
    }else{
        cout << "Khong tim thay nhan vien co ID: " << id << endl ;
    }
}

bool HRM::updateEmployee(string id){
    auto it = staffList.find(id) ;
    if(it == staffList.end()){
        cout << "Nhan vien co ID: " << id << " khong co trong danh sach cua cong ty" << endl ;
        return false ;
    }else{
        int choice ; 
        if(it->second->getPos() == "Manager") choice = 1 ;
        else if(it->second->getPos() == "FullTime") choice = 2 ;
        else choice = 3 ;

        string name ; 
        string Dob, phone_number ; 
        cin.ignore() ;
        cout << "Nhap Ho va Ten: " ; 
        getline(cin, name) ;
        cout << "Nhap Dob: <d/m/y> Ex: 01/04/2007 " ; cin >> Dob ;
        cout << "Nhap sdt: " ; cin >> phone_number ;

        it->second->setFullName(name) ;
        it->second->setDob(Dob) ;
        it->second->setPhoneNumber(phone_number) ;

        if(choice == 1){
            Manager* mgr = (Manager*)(it->second) ;
            int baseslr ;
            cout << "Nhap muc luong co ban: " ;
            cin >> baseslr ;

            cout << "Nhap so nhan vien quan ly: " ; 
            int teamsize ;
            cin >> teamsize ;

            mgr->setBaseSalary(baseslr) ;
            mgr->setTeamSize(teamsize) ;
  
        }else if(choice == 2){
            FullTimeEmployee* ft = (FullTimeEmployee*)(it->second) ;
            int baseslr ;
            cout << "Nhap muc luong co ban: " ;
            cin >> baseslr ;

            double bonus ;
            cout << "Nhap he so thuong: " ;
            cin >> bonus ;

            ft->setBaseSalary(baseslr) ;
            ft->setBonusRate(bonus) ;
        }else{
            PartTimeEmployee* pt = (PartTimeEmployee*)(it->second) ;
        }
        cout << "Da thay doi thong tin nhan vien thanh cong" << endl ;
    }
    return true ;
}

void HRM::sortEmployees(){
    sort(stafflist.begin(), stafflist.end(), cmp) ;
}

bool HRM::deleteEmployee(string id){
    auto it = staffList.find(id) ;
    if(it == staffList.end()) return false ;
    else{
        if(it->second->getPos() == "Manager") m -- ;
        else if(it->second->getPos() == "FullTime") f -- ;
        else p -- ;
        cout << "Da thanh cong xoa nhan vien: " << it->second->getID() << ':' << it->second->getFullName() << endl ;
        delete it->second ;
        staffList.erase(it->first) ;
    }

    stafflist.clear() ;
    for(auto& pair : staffList){
        stafflist.push_back(pair.second) ;
    }
    return true ;
}

void HRM::printStatistics(){
    sortEmployees() ;
    cout << string(60,'-') << endl ;
    cout << "Cong ty co " << m << " Manager gom:" << endl ;
    cout << string(60,'-') << endl ;
    for(auto& emp : stafflist){
        if(emp->getPos() == "Manager")
            cout << emp->getID() << " : " << emp->getFullName() << endl ;
    }
    cout << string(60,'-') << endl ;

    cout << "Cong ty co " << f << " FullTimeEmployee gom:" << endl ;
    cout << string(60,'-') << endl ;
    for(auto& emp : stafflist){
        if(emp->getPos() == "FullTime")
            cout << emp->getID() << " : " << emp->getFullName() << endl ;
    }
    cout << string(60,'-') << endl ;

    cout << "Cong ty co " << p << " PartTimeEmployee gom:" << endl ;
    cout << string(60,'-') << endl ;
    for(auto& emp : stafflist){
        if(emp->getPos() == "PartTime")
            cout << emp->getID() << " : " << emp->getFullName() << endl ;
    }
    cout << string(60,'-') << endl ;
}



