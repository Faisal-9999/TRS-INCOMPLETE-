#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "UserInputHandler.h"

class Food {
private:

	int price;
	std::string name;

public:

	Food(std::string name, int price)  : name(name), price(price) {}
	Food() {}
	
	std::string getName() const {
		return name;
	}

	int getPrice() const {
		return price;
	}

};

class FoodCreator {
public:
	static Food createFood() {
		return Food(StringInput("Food Name: "), IntegerInput("Food Price"));
	}
};

#endif