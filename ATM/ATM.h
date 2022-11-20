#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BankApiInterface {
    virtual bool checkPinNumber(string pinNumber) = 0;
    virtual vector<string> getAccount(string pinNumber) = 0;
    virtual int getBalance(string pinNumber, string account_id) = 0;
    virtual bool deposit(string pinNumber, string account_id, int money) = 0;
    virtual bool withdraw(string pinNumber, string account_id, int money) = 0;
};

class ATM {
public:
    ATM(BankApiInterface* api);
    bool checkPinNumber(string pinNumber);
    vector<string> getAccount();
    void showBalance(string account_id);
    bool deposit(int money);
    bool withdraw(int money);

private:
    string _pinNumber;
    vector<string> _account;
    string _account_id;
    BankApiInterface* _api;
};