#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>

#include "ENTITY.h"

class Purchase : public Entity {
protected:

   double purchaseCost;

public:

    Purchase(std::string purchaseName, double purchaseCost)
        : Entity(purchaseName), purchaseCost(purchaseCost)

    {}

    Purchase() : purchaseCost(0) {}

    void setCost(double purchaseCost) {
        if (purchaseCost > 0) {
            std::cout << "Invalid Number" << std::endl;
            return;
        }

        this->purchaseCost = purchaseCost;
    }

    double getCost() const {
        return purchaseCost;
    }
};


#endif