#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "TICKET.h"
#include "EVENT.h"
#include "CUSTOMER.h"
#include "STAFF.h"

template<typename T>

//Review DATABASE CODE AND ADAPT FOR THE CLASSES

class Database {
private:

    std::vector<T> database;
    std::string FileName;
    std::string databaseName;

public:

    Database(const std::vector<T>& database,const std::string& databaseName, const std::string& FileName) 
        : database(database), FileName(FileName), databaseName(databaseName) {}

    Database() {}

    void add(const T& item) {
        database.push_back(item);
        std::cout << "\n\n " << item.getName() << " added to database\n\n";
    }

    void remove(const T& item) {

        if (database.empty()) {
            std::cout << "\n\nCan't remove anything. Database is empty\n\n";
        }
        else {

            auto index = std::find(database.begin(), database.end(), item);

            if (index != database.end()) {

                database.erase(index);
                std::cout << "\n\nRemoved " << item.getName() << " from the database\n\n";
            }
            else {
                std::cout << "\n\n" << item.getName() << " doesn't exist in the database\n\n";
            }
        }
    }

    void wipeDatabase() {
        if (database.empty()) {
            std::cout << "\n\nDatabase is already empty. Can't Wipe.\n\n";
        }
        else {
            database.clear();
            database.shrink_to_fit();

            std::cout << "Wiped databased called " << database.databaseName << std::endl;
        }
    }

    void printDatabase() {
        std::cout << "\n\n-----" << database.databaseName << std::endl;
        for (int i = 0; i < database.size(); i++) {
            std::cout << i + 1 << "#: \n\n";
            database[i].DisplayInfo();
        }
    }

    void setFileName(std::string) {

    }

    void setDatabase(std::vector<T> database) {
        this->database = database;
    }

    void setDatabaseName(std::string databaseName) {
        this->databaseName = databaseName;
    }

    std::string getFileName() {
        return FileName;
    }

    std::vector <T> getDatabase() {
        return database;
    }
};

class DatabaseUtilities {
public:

    DatabaseUtilities() = delete;

     static std::string lineReader(const std::string& line, int& index) {

         std::string item;

         while (index < line.size() && line[index] != ',') {
             item += line[index];
             index++;
         }

         if (index < line.size() && line[index] == ',') {
             index++;
         }

         return item;
     }

     static void PersonValuesLoader(int& index, const std::string& line, std::string& entityName, int& age, std::string& ID, std::string& password) {

         //Line Format: name, password, ID, age

         entityName = lineReader(line, index);
         password = lineReader(line, index);
         ID = lineReader(line, index);
         age = std::stoi(lineReader(line, index));
     }
};

template<typename T> 
class DatabaseSaverLoader {
public:
    DatabaseSaverLoader() = delete;

};

template<>
class DatabaseSaverLoader<Staff> {
public:

    static void saveDatabase(Database<Staff> database) {

        std::fstream File(database.getFileName(), std::ios::out);

        if (!File.is_open()) {
            std::cout << "\n\nFile called " << database.getFileName() << " doesn't exist" << std::endl;
            File.open(database.getFileName(), std::ios::out);
        }

        for (Staff& staff : database.getDatabase()) {
            //line format is name, password, ID, age, salary,
            std::string line = staff.getName() + "," + staff.getPassword() + "," + staff.getID() + "," + std::to_string(staff.getAge()) + "," + std::to_string(staff.getEmployeeSalary()) + "," + staff.getRole();
            File << line << std::endl;
        }
    }

    static Database<Staff> loadDatabase(std::string FileName) {

        std::fstream File(FileName, std::ios::in);

        if (!File.is_open()) {
            std::cout << "\n\nFile called " << FileName << " doesn't exist" << std::endl;
            return Database<Staff>(std::vector<Staff>{}, "Staff Database", FileName);
        }

        std::vector<Staff> employeeDatabase;
        std::string line;

        while (std::getline(File, line)) {

            int index = 0;
            std::string name, password, ID;
            int age;

            DatabaseUtilities::PersonValuesLoader(index, line, name, age, ID, password);

            double salary = std::stod(DatabaseUtilities::lineReader(line, index));
            std::string role = DatabaseUtilities::lineReader(line, index);

            Staff staff(name, age, ID, salary, role);
            staff.setPassword(password);

            employeeDatabase.push_back(staff);
        }

        return Database<Staff>(employeeDatabase, "Staff Database", FileName);
    }
};


//COMPLETED THIS MIGHT NEED TO RE-REVIEW AND OPTIMIZE IN THE FUTURE

template<>
class DatabaseSaverLoader<Customer> {
public:

    static void saveDatabase(Database<Customer> database) {

        std::fstream File(database.getFileName(), std::ios::out );

        if (!File.is_open()) {
            std::cout << "\n\nFile called " << database.getFileName() << " doesn't exist" << std::endl;
            std::cout << "Crreating File..." << std::endl;
            File.open(database.getFileName(), std::ios::out);
        }

        for (Customer& cust : database.getDatabase()) {

            std::string line = cust.getName() + "," + cust.getPassword() + "," + cust.getID() + "," + std::to_string(cust.getAge()) + ",";
            File << line << std::endl;

            line.clear();

            for (int i = 0; i < cust.getEventsAttended().size(); i++) {
                if (i == 0 || i == cust.getEventsAttended().size() - 1) {
                    line += cust.getEventsAttended()[i].getEventName() + "." + cust.getEventsAttended()[i].getEventDate();
                }
                
                line += "," + cust.getEventsAttended()[i].getEventName() + "." + cust.getEventsAttended()[i].getEventDate();
            }

            File << line << std::endl;

            line.clear();

            for (int i = 0; i < cust.getPurchaseHistory().size(); i++) {
                if (i == 0 || i == cust.getPurchaseHistory().size() - 1) {
                    line += cust.getPurchaseHistory()[i].getPurchaseName() + "." + std::to_string(cust.getPurchaseHistory()[i].getPurchaseCost());
                }

                line += "," + cust.getPurchaseHistory()[i].getPurchaseName() + "." + std::to_string(cust.getPurchaseHistory()[i].getPurchaseCost());
            }

            File << line << std::endl;
        }
    }

    static Database<Customer> loadDatabase(std::string FileName) {
        std::fstream File(FileName, std::ios::in);

        if (!File.is_open()) {
            std::cout << "\n\nFile called " << FileName << " doesn't exist" << std::endl;
            return Database<Customer>(std::vector<Customer>{}, "Customer Database", FileName);
        }

        std::vector<Customer> customerDatabase;
        std::vector<Event> eventsAttended;
        std::vector<Purchase> purchaseHistory;
        std::string line;

        while (std::getline(File, line)) {

            int index = 0;
            std::string name, password, ID;
            int age;

            Customer cust;

            DatabaseUtilities::PersonValuesLoader(index, line, name, age, ID, password);

            cust.setName(name);
            cust.setAge(age);
            cust.setID(ID);
            cust.setPassword(password);

            line.clear();


            std::getline(File, line);

            index = 0;

            bool scanningEventName = true;

            std::string eventName;
            std::string eventDate;
            

            while (index < line.size()) {

                if (line[index] == '.') {
                    scanningEventName = false;
                    index++;
                }
                else if (line[index] == ',') {

                    cust.addEventToHistory(Event(eventName, eventDate));
                    eventName.clear();
                    eventDate.clear();

                    scanningEventName = true;
                    index++;
                }
                

                if (scanningEventName) {
                    eventName += line[index];
                }
                else {
                    eventDate += line[index];
                }


                index++;
            }

            line.clear();

            index = 0;

            std::getline(File, line);

            bool scanningPurchaseName = true;

            std::string purchaseName;
            std::string purchaseCost;

            while (index < line.size()) {

                if (line[index] == '.') {
                    scanningPurchaseName = false;
                    index++;
                }
                else if (line[index] == ',') {

                    cust.addPurchaseToHistory(Purchase(purchaseName, std::stod(purchaseCost)));
                    purchaseName.clear();
                    purchaseCost.clear();

                    scanningPurchaseName = true;
                    index++;
                }


                if (scanningPurchaseName) {
                    purchaseName += line[index];
                }
                else {
                    purchaseCost += line[index];
                }

                index++;
            }

            customerDatabase.push_back(cust);

        }

        return Database<Customer>(customerDatabase, "Customer Database", FileName);
    }
};

template<>
class DatabaseSaverLoader<Ticket> {

};

template<>
class DatabaseSaverLoader<Event> {

};

#endif