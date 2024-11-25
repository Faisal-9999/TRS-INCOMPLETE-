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
    double amountSpent;
    std::string currentTicketType;
    std::vector <Event> eventsAttended;
    std::vector <Purchase> purchaseHistory;


public:

    Customer(const std::string name, const int age, const std::string ID, std::vector<Event> eventsAttended, std::vector<Purchase> purchaseHistory) 
        : Person(name, age, ID), eventsAttended(eventsAttended), purchaseHistory(purchaseHistory) 
    {}

    Customer(const Customer& customer) 
        : Person(customer.name, customer.age, customer.ID), eventsAttended(customer.eventsAttended), purchaseHistory(customer.purchaseHistory)
    {}

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

class NormalCustomer : public Customer {
public:

    NormalCustomer(std::string name, int age, std::string ID, std::vector<Event> eventsAttended, std::vector<Purchase> purchaseHistory) 
        : Customer(name, age, ID, eventsAttended, purchaseHistory)
    {}

    NormalCustomer(const NormalCustomer& normal) 
        : Customer(normal) 
    {}

    NormalCustomer() {}
};


class VIPCustomer : public Customer {
public:

    VIPCustomer(std::string name, int age, std::string ID, std::vector<Event> eventsAttended, std::vector<Purchase> purchaseHistory)
        : Customer(name, age, ID, eventsAttended, purchaseHistory)
    {}

    VIPCustomer(const VIPCustomer& VIP) 
        : Customer(VIP) 
    {}

    VIPCustomer() {}

    void getPremium() {

    }

};

class CustomerCreator {
private:

};

#endif
