#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "Employee.h"

class HRM {
private: 
    std::unordered_map<std::string, Employee*> staffList ;
    std::vector<Employee*> stafflist ;
    int m = 0 ; int f = 0 ; int p = 0 ;
public: 
    HRM() ;
    ~HRM() ;

    static bool cmp(Employee* a, Employee* b);

    /**
     * Thêm nhân viên vào danh sách của công ty
    */
    void addEmployee();
    /**
     * In danh sách nhân viên của công ty
    */
    void displayListEmployees() const;
    /**
     * In bảng lương cho toàn bộ nhân viên trong công ty
     */
    void calculateTotalPayroll() ;
    /**
     * Tìm thông tin nhân viên bằng ID
    */
    void searchEmployeeByID(std::string id) const;
    /**
     * Chỉnh sửa thông tin nhân viên 
     */
    bool updateEmployee(std::string id);
    /**
     * Xóa nhân viên khỏi danh sách 
     */
    bool deleteEmployee(std::string id);
    /**
     * In các chức vụ nhân viên trong công ty
     */
    void printStatistics() ;
    /**
     * Sắp xếp giảm dần theo lương tăng dần theo tên 
     */
    void sortEmployees() ;

};

