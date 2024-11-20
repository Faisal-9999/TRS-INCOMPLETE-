#include <iostream>
#include <random>
#include <string>
#include <stdexcept>
using namespace std;

string StringInput(string characteristic) {

    string input;

    cout << "\n\nEnter " << characteristic << ": ";
    getline(cin, input);

    return input;
}

int IntegerInput(string characteristic) {

    int input;

    while (true)
    {
        cout << "Enter " << characteristic << ": ";
        cin >> input;

        if (cin.fail()) {
            cout << "\n\nERROR: ENTER A VALID INTEGER\n\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }
    }

    return input;
}

double DoubleInput(string characteristic) {
    double input;


    while (true)
    {
        cout << "Enter " << characteristic << ": ";
        cin >> input;

        if (cin.fail()) {
            cout << "\n\nERROR: ENTER A VALID INTEGER\n\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }
    }

    return input;
}

string randomIDGenerator() {

    const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string NUMS = "0123456789";

    random_device rand;
    mt19937 gen(rand());

    uniform_int_distribution<> dist(0, NUMS.size() - 1);

    char ID[9];

    for (int i = 0; i < 3; i++) {

        if (i == 0) {
            ID[i] = '#';
        }
        else {
            ID[i] = NUMS[dist(gen)];
        }
    }

    uniform_int_distribution<> dist2(0, UPPERCASE.size() - 1);

    for (int i = 3; i < 8; i++) {
        ID[i] = UPPERCASE[dist2(gen)];
    }

    ID[8] = '\0';

    return string(ID);
}