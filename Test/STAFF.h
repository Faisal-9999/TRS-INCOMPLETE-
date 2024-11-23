#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <vector>
#include <unordered_map>

template<typename T>
class Database;

class Staff : public Person {
protected:

    double salary;
    std::string role;

public:

    Staff(const std::string name, const int age, const std::string EmployeeID, const double salary, const std::string role)
        : salary(salary), role(role), Person(name, age, EmployeeID) {
    };

    Staff() {};

    void setEmployeeSalary(double& salary) {
        this->salary = salary;
    }

    double getEmployeeSalary() const {
        return salary;
    }

    void setRole(std::string& role) {
        this->role = role;
    }

    std::string getRole() const {
        return role;
    }

    void displayInfo() override {
        
    }
};

class FoodVendor : public Staff {

private:

    std::vector<Food> FoodItems;
    std::unordered_map <std::string, int> FoodItemsSold;

public:

    FoodVendor(std::string name, int age, std::string EmployeeID, double salary, std::string role)
        : FoodItems({ Food("Burger", 100), Food("Fries", 50), Food("Pizza", 150) }),
        Staff(name, age, EmployeeID, salary, role) {
    };

    FoodVendor() {};

    void sellFood() {};
    void addNewItem() {};
    void removeItem() {};

    void displayInfo() override {

    }

};

class Manager : public Staff {

public:

    Manager(std::string name, int age, std::string EmployeeID, double salary, std::string role) :
        Staff(name, age, EmployeeID, salary, role) {
    };

    Manager() {};
    
    void changeEmployeeRole(const Staff& staff) {

    }

    void changeEmployeeSalary(const Staff& staff) {

    }

    void checkItemsSold(FoodVendor& vendor) {

    }

    template<typename T>
    void viewEmployees(Database<T>& database) {
        database.print();
    }

    void displayInfo() override {

    }

};

class Janitor : public Staff {
public:

    Janitor(std::string name, int age, std::string EmployeeID, double salary, std::string role) :
        Staff(name, age, EmployeeID, salary, role) {
    };

    Janitor() {};

    void displayInfo() override {

    }
};

class StaffCreator {
public:

    static Janitor createJanitor() {
        Janitor jan(StringInput("Janitor Name"), IntegerInput("Janitor Age"), randomIDGenerator(), DoubleInput("Janitor Salary"), "Janitor");
        jan.setPassword(StringInput("Password"));
        return jan;
    }

    static Manager createManager() {
        Manager Man(StringInput("Manger Name"), IntegerInput("Manager Age"), randomIDGenerator(), DoubleInput("Manager Salary"), "Manager");
        Man.setPassword(StringInput("Password"));
        return Man;
    }

    static FoodVendor createFoodvendor() {
        FoodVendor Ven(StringInput("Vendor Name"), IntegerInput("Vendor Age"), randomIDGenerator(), DoubleInput("Vendor Salary"), "Food Vendor");
        Ven.setPassword(StringInput("Password"));
        return Ven;
    }
};

class StaffSaverLoader {
public:

    static Janitor loadJanitor(std::string name, std::string password) {
        
    }

    static Manager loadManager(std::string name, std::string password) {
        Manager man;
    }

    static FoodVendor loadVendor(std::string name, std::string password) {
        FoodVendor Ven;
    }
};


#endif