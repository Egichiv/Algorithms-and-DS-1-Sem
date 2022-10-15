#include <iostream>

using namespace std;

struct fridge {
    float milk;
    float meat;
    float cheese_pieces;
    float scooby_snacks;
};

void fridge_operation (fridge* x, int y, float z) {
    switch (y) {
        case 1:
            if (x->milk + z >= 0) {
                x->milk = x->milk + z;
                cout << "\nThere is " << x->milk << "l of milk in the fridge now\n\n";
            }
            else {
                cout << "\nOperation is not possible\n\n";
            }
            break;

        case 2:
            if (x->meat + z >= 0) {
                x->meat = x->meat + z;
                cout << "\nThere are " << x->meat << "kg of meat in the fridge now\n\n";
            }
            else {
                cout << "\nOperation is not possible\n\n";
            }
            break;

        case 3:
            if (x->cheese_pieces + z >= 0) {
                x->cheese_pieces = x->cheese_pieces + z;
                cout << "\nThere are " << x->cheese_pieces << " pieces of cheese in the fridge now\n\n";
            }
            else {
                cout << "\nOperation is not possible\n\n";
            }
            break;

        case 4:
            if (x->scooby_snacks + z >= 0) {
                x->scooby_snacks = x->scooby_snacks + z;
                cout << "\nThere are " << x->scooby_snacks << " scooby-snacks in the fridge now\n\n";
            }
            else {
                cout << "\nOperation is not possible\n\n";
            }
            break;

        default:
            cout << "\nInvalid Input\n";
            cout << "\nNu ili ti Invalid, lol (:\n";
            break;
    }
}

void fridge_info (fridge x, int y) {
    switch (y) {
        case 1:
            cout << "\nThere is " << x.milk << "l of milk in the fridge\n\n";
            break;

        case 2:
            cout << "\nThere are " << x.meat << "kg of meat in the fridge\n\n";
            break;

        case 3:
            cout << "\nThere are " << x.cheese_pieces << " pieces of cheese in the fridge\n\n";
            break;

        case 4:
            cout << "\nThere are " << x.scooby_snacks << " scooby-snacks in the fridge\n\n";
            break;

        case 5:
            cout << "\nThere is " << x.milk << "l of milk in the fridge\n";
            cout << "\nThere are " << x.meat << "kg of meat in the fridge\n";
            cout << "\nThere are " << x.cheese_pieces << " pieces of cheese in the fridge\n";
            cout << "\nThere are " << x.scooby_snacks << " scooby-snacks in the fridge\n\n";
            break;

        default:
            cout << "\nInvalid Input\n";
            cout << "\nNu ili ti Invalid, lol (:\n";
            break;
    }
}

int main() {
    struct fridge bosch = { 0.2, 3.5, 2, 20};
    struct fridge samsung = { 0, 0, 100, 0};
    struct fridge* bosch_portal = &bosch;
    struct fridge* samsung_portal = &samsung;

    int choice;
    cout << "Do you want to play with fridges?\n(1 - Yes, 0 - No)\n";
    cin >> choice;

    if (choice == 1 || choice == 0) {
        cout << "\nOK\n\n";
    }
    else {
        cout << "\nInvalid Input\n";
        cout << "\nNu ili ti Invalid, lol (:\n";
        exit(0);
    }

    float value;
    while (choice == 1) {

        cout << "\nWhich fridge do you want to play with?\n(1 - Bosch, 2 - Samsung)\n";
        cin >> choice;

        if (choice == 1) {

            cout << "\nYou can check the information about the food in the fridge, or take/put some food from/in it.\n(1 - check info, 2 - do an operation)\n";
            cin >> choice;

            if (choice == 1) {

                cout << "\n1 - milk / 2 - meat / 3 - cheese pieces / 4 - scooby-snacks / 5 - everything\n";
                cin >> choice;
                fridge_info(bosch, choice);

            }
            else if (choice == 2) {

                cout << "\n1 - milk / 2 - meat / 3 - cheese pieces / 4 - scooby-snacks\n";
                cin >> choice;
                cout << "\nChoose the value to add (negative to do subtraction)\n";
                cin >> value;
                fridge_operation(bosch_portal, choice, value);

            }
            else {
                cout << "\nInvalid Input\n";
                cout << "\nNu ili ti Invalid, lol (:\n";
                exit(0);
            }
        }
        else if (choice == 2) {

            cout << "\nYou can check the information about the food in the fridge, or take/put some food from/in it.\n(1 - check info, 2 - do an operation)\n";
            cin >> choice;

            if (choice == 1) {

                cout << "\n1 - milk / 2 - meat / 3 - cheese pieces / 4 - scooby-snacks / 5 - everything\n";
                cin >> choice;
                fridge_info(samsung, choice);

            }
            else if (choice == 2) {

                cout << "\n1 - milk / 2 - meat / 3 - cheese pieces / 4 - scooby-snacks\n";
                cin >> choice;
                cout << "\nChoose the value to add (negative to do subtraction)\n";
                cin >> value;
                fridge_operation(samsung_portal, choice, value);

            }
            else {
                cout << "\nInvalid Input\n";
                cout << "\nNu ili ti Invalid, lol (:\n";
                exit(0);
            }
        }
        else {
            cout << "\nInvalid Input\n";
            cout << "\nNu ili ti Invalid, lol (:\n";
            exit(0);
        }

        cout << "\nStill wanna play? (1 - Yes, 0 - No)\n";
        cin >> choice;
    }
    cout << "\nSeems you don't want to play with fridges anymore. Finally.\n";

    //struct fridge garbage_fridges[3] = {1, 0, 0, 0}; //также можно потрогать массив структур, но ничо интересного.
    //cout << garbage_fridges[0].milk << garbage_fridges[1].milk << garbage_fridges[2].milk;
    //cin >> garbage_fridges[0].milk;
    //cin >> garbage_fridges[1].meat;
    //cin >> garbage_fridges[2].scooby_snacks >> garbage_fridges[2].cheese_pieces;

    return 0;
}
