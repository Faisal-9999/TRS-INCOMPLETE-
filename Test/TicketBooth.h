#ifndef TICKETBOOTH_H
#define TICKETBOOTH_H

#include <iostream>
#include <vector>

#include "UserInputHandler.h"

class TicketBooth {
private:

	const std::string FoodVendorFileName = "FoodVendor.txt";
	const std::string ManagerFileName = "Manager.txt";
	const std::string VIPFileName = "Customer.txt";
	const std::string NormalCustFileName = "NormalCustomer.txt";


	Database<Staff> staffDatabase;
	Database<Ticket> ticketDatabase;
	Database<Customer> customerDatabase;
	Database<Event> eventDatabase;


	Staff* staff = nullptr;
	Customer* customer = nullptr;
	Admin* admin = nullptr;

	void startUp() {

	}


	void menu(std::string title, std::vector<std::string> choices) {
		int choice = -1;

		while (choice != choices.size()) {
			std::cout << "-----" << title << "-----" << std::endl;

			choice = optionsPrinter(choices);
		}
	}

	int optionsPrinter(std::vector<std::string> options) {
		
		for (int i = 0; i < options.size(); i++) {
			std::cout << i + 1 << ". " << options[i] << std::endl;
		}

		return IntegerInput("Choice (1 - " + std::to_string(options.size()));
	}

public:

	void start() {

	}
};


#endif