#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

#include "DATABASE.h"

class Admin : public Entity {
private:

	const std::string password = "1234";

public:
	Admin() {
		std::cout << "\n\n-----ADMIN LOGGING IN-----" << std::endl;
	}
	~Admin() {
		std::cout << "\n\n-----ADMIN LOGGING OUT-----" << std::endl;
	}

	bool login(std::string password) {
		return (this->password == password ? true : false);
	}

	template<typename T>
	void readDatabase(Database<T>& database) {
		database.print();
	}

	template<typename T>
	void printDatabaseDetails(Database<T>& database) {
		database.printDetails();
	}

	template<typename T>
	void clearDatabase(Database<T>& database) {
		database.wipe();
	}

	template<typename T>
	void addNewItemToDatabase(Database<T>& database, T& item) {
		database.add(item);
	}

	template<typename T>
	void removeItemFromDatabase(Database<T>& database, T& item) {
		database.remove(item);
	}
};

#endif