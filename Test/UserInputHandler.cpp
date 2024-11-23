#include <iostream>
#include <random>
#include <string>
#include <stdexcept>

std::string StringInput(std::string characteristic) {

    std::string input;

    while (true){
        bool invalidCharacter = false;
        std::cout << "\nEnter " << characteristic << ": ";
        std::getline(std::cin, input);

        for (char& a : input) {
            if (a == '.' || a == ',') {
                invalidCharacter = true;
                break;
            }
        }

        if (invalidCharacter) {
            std::cout << "Input failed. Can't contain characters ',' and '.'" << std::endl;
            std::cout << "TRY AGAIN." << std::endl;
            continue;
        }
        else {
            break;
        }
    }

    return input;
}

int IntegerInput(std::string characteristic) {

    int input;

    while (true)
    {
        std::cout << "Enter " << characteristic << ": ";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cout << "\n\nERROR: ENTER A VALID INTEGER\n\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            break;
        }
    }

    return input;
}

double DoubleInput(std::string characteristic) {
    double input;


    while (true)
    {
        std::cout << "Enter " << characteristic << ": ";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cout << "\n\nERROR: ENTER A VALID INTEGER\n\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            break;
        }
    }

    return input;
}

std::string randomIDGenerator() {

    const std::string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string NUMS = "0123456789";

    std::random_device rand;
    std::mt19937 gen(rand());

    std::uniform_int_distribution<> dist(0, NUMS.size() - 1);

    char ID[9];

    for (int i = 0; i < 3; i++) {

        if (i == 0) {
            ID[i] = '#';
        }
        else {
            ID[i] = NUMS[dist(gen)];
        }
    }

    std::uniform_int_distribution<> dist2(0, UPPERCASE.size() - 1);

    for (int i = 3; i < 8; i++) {
        ID[i] = UPPERCASE[dist2(gen)];
    }

    ID[8] = '\0';

    return std::string(ID);
}