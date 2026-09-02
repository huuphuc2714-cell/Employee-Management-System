#include <iostream>
#include <string>
#include "include/HRM.h"

using namespace std;

void printMenu() {
    cout << "\n=========== QUAN LY NHAN SU ===========" << endl;
    cout << "1. Them nhan vien" << endl;
    cout << "2. Hien thi danh sach nhan vien" << endl;
    cout << "3. Tim kiem nhan vien theo ID" << endl;
    cout << "4. Cap nhat thong tin nhan vien" << endl;
    cout << "5. Sap xep danh sach (Theo luong & Ten)" << endl;
    cout << "6. Xoa nhan vien" << endl;
    cout << "7. In bang luong thang" << endl ;
    cout << "8. In cac chuc vu cua nhan vien" << endl ;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "=======================================" << endl;
    cout << "Nhap lua chon cua ban: " << endl ;
}

int main() {
    // freopen("input.txt", "r", stdin);

    HRM company;
    int choice;

    while (true) {
        printMenu();
        if (!(cin >> choice)) break; 
        
        if (choice == 0) {
            cout << "Thoat chuong trinh thanh cong!" << endl;
            break;
        } else if (choice == 1) {
            company.addEmployee();
        } else if (choice == 2) {
            company.displayListEmployees();
        } else if (choice == 3) {
            string id;
            cout << "Nhap ID can tim: ";
            cin >> id;
            company.searchEmployeeByID(id);
        } else if (choice == 4) {
            string id;
            cout << "Nhap ID cua nhan vien can cap nhat thong tin: ";
            cin >> id;
            company.updateEmployee(id);
        } else if (choice == 5) {
            company.sortEmployees();
            cout << "Da sap xep danh sach! Hay chon menu 2 de xem ket qua." << endl;
        } else if (choice == 6) {
            string id;
            cout << "Nhap ID can xoa: ";
            cin >> id;
            company.deleteEmployee(id);
        } else if (choice == 7) {
            company.calculateTotalPayroll() ;
        } else if (choice == 8) {
            company.printStatistics() ;
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
    }

    return 0;
}

