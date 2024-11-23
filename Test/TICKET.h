#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "PURCHASE.h"

class Ticket : public Purchase {
private:
	std::string ticketID;
public:

	Ticket(std::string name, std::string ID, double cost) 
		: Purchase(name, cost), ticketID(ID) 
	{}

	Ticket() {}

	std::string getID() {
		return ticketID;
	}
};

class TicketCreator {

};


#endif