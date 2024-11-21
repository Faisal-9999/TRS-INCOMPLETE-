#ifndef FOOD_H
#define FOOD_H

#include <iostream>


class Food : public Purchase {
private:

	int price;

public:

	Food(std::string name, int price)  : Purchase(name, price) {}
	Food() {}
	
	int getPrice() const {
		return price;
	}

	void setPrice(int price) {
		if (price <= 0) {
			std::cout << "Invalid price, Can't be 0 or any lesser value";
			return;
		}

		this->price = price;
	}

};

class FoodCreator {
public:
	static Food createFood() {
		return Food(StringInput("Food Name: "), IntegerInput("Food Price"));
	}
};

#endif