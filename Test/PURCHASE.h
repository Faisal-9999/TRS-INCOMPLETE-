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

    Purchase() {}

    void setCost(double purchaseCost) {
        this->purchaseCost = purchaseCost;
    }

    double getCost() const {
        return purchaseCost;
    }
};


#endif