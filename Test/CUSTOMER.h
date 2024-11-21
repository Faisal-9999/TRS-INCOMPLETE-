#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "PERSON.h"
#include "FOOD.h"
#include "EVENT.h"
#include "PURCHASE.h"

class Customer : public Person {
protected:

    int ticketsBought;
    bool currentTicketHolder;
    double amountSpent;
    std::string currentTicketType;
    std::vector <Event> eventsAttended;
    std::vector <Purchase> purchaseHistory;


public:

    Customer(const std::string name, const int age, const std::string ID,
        std::vector<Event> eventsAttended, std::vector<Purchase> purchaseHistory) 
        : Person(name, age, ID), eventsAttended(eventsAttended), purchaseHistory(purchaseHistory) {}

    Customer() {}
    
    std::vector<Event> getEventsAttended() {
        return eventsAttended;
    }

    std::vector<Purchase> getPurchaseHistory() {
        return purchaseHistory;
    }

    void addEventToHistory(const Event& event) {
        eventsAttended.push_back(event);
    }

    void addPurchaseToHistory(const Purchase& purchase) {
        purchaseHistory.push_back(purchase);
    }

    void setPurchaseHistory(std::vector<Purchase> purchaseHistory) {
        this->purchaseHistory = purchaseHistory;
    }

    void setEventsAttended(std::vector<Event> eventsAttended) {
        this->eventsAttended = eventsAttended;
    }

    void bookTickets() {

    }

    void cancelTickets() {

    }

    void upgradeTicket() {

    }

    void viewEvents() {

    }

    void viewPurchaseHistory() {

    }

    void viewEventsAttended() {

    }

    void deleteAccount() {

    }

    void buyFood() {

    }

    void displayInfo() override {

    }


};


class VIPCustomer : public Customer {
public:

};

class NormalCustomer : public Customer {

};

class CustomerCreator {
private:

};

class CustomerSaverLoader {

};

#endif
