#include <iostream>

#include "UserInputHandler.h"
#include "DATABASE.h"
#include "FOOD.h"
#include "PERSON.h"
#include "TICKET.h"
#include "ADMIN.h"

class TicketBooth {



public:

     TicketBooth() { std::cout << "-----STARTING SYSTEM-----\n\n"; };
    ~TicketBooth() { std::cout << "\n\n-----EXITING SYSTEM-----"; };

    void start() {
        
    }

private:

};

int main()
{
    TicketBooth ticketbooth;
    ticketbooth.start();
}