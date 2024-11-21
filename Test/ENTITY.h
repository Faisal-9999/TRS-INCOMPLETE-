#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>


class Entity {
protected:
	std::string name;
public:

	Entity(std::string name) : name(name) {}
	Entity() {}

	void setName(std::string& name) {
		this->name = name;
	}

	std::string getName() {
		return name;
	}

	virtual void displayInfo() {
		std::cout << "Item Name: " << name << std::endl;
	}
};


#endif