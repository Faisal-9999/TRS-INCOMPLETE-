#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

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

	void addNew

};

#endif