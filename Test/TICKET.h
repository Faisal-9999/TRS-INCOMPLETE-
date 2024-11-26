#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "PURCHASE.h"
#include "UserInputHandler.h"

class Ticket : public Purchase {
private:
	std::string ticketID;
public:

	Ticket(const std::string name, const std::string ID, const double cost) 
		: Purchase(name, cost), ticketID(ID) 
	{}

	Ticket(const Ticket& ticket)
		: Purchase(ticket.name, ticket.purchaseCost), ticketID(ticket.ticketID)
	{}

	Ticket() {}

	std::string getID() {
		return ticketID;
	}
};

class TicketCreator {
private:
	TicketCreator() {}
public:
	
	static Ticket createTicket() {
		return Ticket(StringInput("Ticket Name"), randomIDGenerator(), DoubleInput("Ticket Price"));
	}
};


#endif