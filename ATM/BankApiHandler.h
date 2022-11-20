#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
\
class DummyApi : public BankApiInterface {
public:
    DummyApi();
    void insertTestset(string pinNumber, map<string, int> account);

    // Implementation of interface
    bool checkPinNumber(string pinNumber);
    vector<string> getAccount(string pinNumber);
    int getBalance(string pinNumber, string account_id);
    bool deposit(string pinNumber, string account_id, int money);
    bool withdraw(string pinNumber, string account_id, int money);
private:
    map<string, map<string, int>> _bank;  // {pinNumber, {account, balance}}
};