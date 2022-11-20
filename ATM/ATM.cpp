#include "ATM.h"

using namespace std;

ATM::ATM(BankApiInterface* api) {
    // 1. Insert PIN number
    cout << "This is a ATM" << endl;
    _api = api;

};

bool ATM::checkPinNumber(string pinNumber) {
    // 2. Check PIN number
    if (_api->checkPinNumber(pinNumber)) {
        _pinNumber = pinNumber;
        cout << "Your PIN number is verified." << endl << endl;
        return true;
    }
    else {
        cout << "A wrong PIN number." << endl << endl;
        return false;
    }
}

vector<string> ATM::getAccount() {
    // 2. Show accounts 
    _account = _api->getAccount(_pinNumber);

    cout << "Your Accounts are:" << endl;
    for (auto &elem : _account) {
        cout << elem << endl;
    }
    cout << endl;
    cout << "Select your account:" << endl;
    return _account;
}

void ATM::showBalance(string account_id) {
    // 3. Select a account and show a balance / Ask to withdraw, deposit or leave 
    _account_id = account_id;
    int balance = _api->getBalance(_pinNumber, account_id);

    cout << "Your balance is: " << to_string(balance) << endl << endl;
}

bool ATM::deposit(int money) {
    // 4. Deposit

    cout << "Your money is deposited." << endl;

    if (_api->deposit(_pinNumber, _account_id, money)) {
        return true;
    }
    else {
        return false;
    }
}

bool ATM::withdraw(int money) {
    // 5. Withdraw
    int balance = _api->getBalance(_pinNumber, _account_id);

    if (balance - money < 0) {
        cout << "The balance is insufficient." << endl;
        return false;
    }
    else {
        if (_api->withdraw(_pinNumber, _account_id, money)) {
            cout << "Your deposit has been successfully deposited." << endl;
            return true;
        }
        else {
            cout << "There is a problem with our system." << endl;
            return false;
        }
    }
}