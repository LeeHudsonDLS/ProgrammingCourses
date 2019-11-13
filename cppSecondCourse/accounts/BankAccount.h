//
// Created by jjc62351 on 03/10/2019.
//

#ifndef ACCOUNTS_BANKACCOUNT_H
#define ACCOUNTS_BANKACCOUNT_H

#include <string>

class BankAccount {
public:
    BankAccount(std::string name, int accNumber);
    void deposit(int amount);
    void display();

private:
    std::string name;
    int accNumber;
    float balance;

};


#endif //ACCOUNTS_BANKACCOUNT_H
