//
// Created by jjc62351 on 03/10/2019.
//

#ifndef ACCOUNTS_CREDITACCOUNT_H
#define ACCOUNTS_CREDITACCOUNT_H

#include "BankAccount.h"

class CreditAccount: public BankAccount {
public:
    CreditAccount(std::string name, int accNumber);

};


#endif //ACCOUNTS_CREDITACCOUNT_H
