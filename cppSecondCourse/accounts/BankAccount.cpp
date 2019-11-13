//
// Created by jjc62351 on 03/10/2019.
//

#include "BankAccount.h"
#include <iostream>
#include <stdio.h>

BankAccount::BankAccount(std::string name, int accNumber): name(name),accNumber(accNumber), balance(0) {

}
void BankAccount::display() {
    printf("AccName: %s, AccNo: %d, balance %f\n",name.c_str(),accNumber,balance);
}

void BankAccount::deposit(int amount) {
    balance+=amount;
}