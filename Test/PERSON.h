#ifndef PERSON_H
#define PERSON_H


#include <iostream>

class Person {
protected:
    std::string name;
    int age;
    std::string ID;
    std::string password;

public:
    
    Person(std::string name, int age, std::string ID) 
        : name(name), age(age), ID(ID) {};

    Person() {}

    void setPassword(std::string password) {
        this->password = password;
    }

    std::string getPassword() {
        return password;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    std::string getID() const {
        return ID;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setID(std::string ID) {
        this->ID = ID;
    }

    virtual void DisplayInfo() = 0;
};




#endif
