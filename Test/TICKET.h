#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "PURCHASE.h"

class Ticket : public Purchase {
private:
	std::string ticketID;
public:

	std::string getID() {
		return ticketID;
	}
};

class TicketCreator {

};


#endif