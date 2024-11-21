#ifndef PERSON_H
#define PERSON_H


#include <iostream>

class Person : public Entity {

protected:

    int age;
    std::string ID;
    std::string password;

public:
    
    Person(std::string name, int age, std::string ID) 
        : Entity(name), age(age), ID(ID) {};

    Person() {}

    void setPassword(std::string password) {
        this->password = password;
    }

    std::string getPassword() {
        return password;
    }

    int getAge() const {
        return age;
    }

    std::string getID() const {
        return ID;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setID(std::string ID) {
        this->ID = ID;
    }
};




#endif
