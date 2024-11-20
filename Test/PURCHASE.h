#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>

class Purchase {
private:

   std::string purchaseName;
   double purchaseCost;

public:

    Purchase(std::string purchaseName, double purchaseCost)
        : purchaseName(purchaseName), purchaseCost(purchaseCost)

    {}

    Purchase() {}

    void setPurchaseName(std::string purchaseName) {
        this->purchaseName = purchaseName;
    }

    std::string getPurchaseName() const {
        return purchaseName;
    }

    void setPurchaseCost(double purchaseCost) {
        this->purchaseCost = purchaseCost;
    }

    double getPurchaseCost() const {
        return purchaseCost;
    }
};


#endif