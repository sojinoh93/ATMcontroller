#include "ATM.h"
#include "BankApiHandler.h"

using namespace std;

DummyApi::DummyApi() {}

void DummyApi::insertTestset(string pinNumber, map<string, int> account) {
    _bank.insert({ pinNumber, account });
}

bool DummyApi::checkPinNumber(string pinNumber) {
    if (_bank.count(pinNumber)) {
        return true;
    }
    return false;
}

vector<string> DummyApi::getAccount(string pinNumber) {
    vector<string> account;

    if (_bank.count(pinNumber)) {

        for (auto &elem : _bank[pinNumber]) {
            account.push_back(elem.first);
        }
    }
    return account;
}

int DummyApi::getBalance(string pinNumber, string account_id) {
    if (_bank.count(pinNumber)) {
        if (_bank[pinNumber].count(account_id)) {
            return _bank[pinNumber][account_id];
        }
    }
    return 0;
};

bool DummyApi::deposit(string pinNumber, string account_id, int money) {
    if (_bank.count(pinNumber)) {
        if (_bank[pinNumber].count(account_id)) {
            _bank[pinNumber][account_id] += money;
            return true;
        }
    }
    return false;
};

bool DummyApi::withdraw(string pinNumber, string account_id, int money) {
    if (_bank.count(pinNumber)) {
        if (_bank[pinNumber].count(account_id)) {
            int balance = _bank[pinNumber][account_id] - money;
            
            if (balance > 0) {
                _bank[pinNumber][account_id] = balance;
                return true;
            }
        }
    }
    return false;
};