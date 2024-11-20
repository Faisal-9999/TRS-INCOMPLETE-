#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

class Admin {

private:

	const std::string password = "1234";

public:
	~Admin() {
		std::cout << "\n\n-----ADMIN LOGGING OUT-----\n\n";
	}

};

#endif