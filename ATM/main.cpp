#include <iostream>
#include <string>
#include "ATM.h"
#include "BankApiHandler.h"

using namespace std;

/* SUMMARY
* This project consists of two parts - ATM and BankApiHandler 
* ATM code has implemented basic functions of ATM which interact with bank API interface.
* You can check a 'BankApiInterface' on ATM.h
* BankApiHandler code is actual implementation of 'BankApiInterface'. 
* I made a dummy class.
* 
* As the code uses the interface, 
* The thing needs to be modified for future integration is BankApiHandler 
* accoding to real bank API.
*/

int main()
{
    // Dummy API for testing ATM functions
    DummyApi* dummyApi = new DummyApi();
    dummyApi->insertTestset("101", {
        { "1-222", 0 }, { "1-333", 500 }, { "1-444", 20 }
    });

    ATM* atm = new ATM(dummyApi);
    string pinNumber;
    string account;
    string menu;
    string money;

    while (true) {
        cout << "Insert your PIN number: " << endl;
        cin >> pinNumber;
        if (atm->checkPinNumber(pinNumber)) {
            atm->getAccount();
            cin >> account;
            atm->showBalance(account);

            cout << "Select a menu" << endl;
            cout << "1: deposit / 2: withdraw / 3. leave" << endl;
            cin >> menu;

            if (menu == "1") {
                cout << "Insert your money: " << endl;
                cin >> money;
                atm->deposit(stoi(money));
                atm->showBalance(account);
            }
            else if (menu == "2") {
                cout << "Enter amount: " << endl;
                cin >> money;
                atm->withdraw(stoi(money));
                atm->showBalance(account);
            }
            else if (menu == "3") {
                cout << "Thank you for using" << endl;
                cout << endl;
            }
        }
    }

    return 0;
}