cmake_minimum_required(VERSION 3.14)
project(accounts)

set(CMAKE_CXX_STANDARD 14)

add_executable(accounts main.cpp BankAccount.cpp BankAccount.h CreditAccount.cpp CreditAccount.h SavingsAccount.cpp SavingsAccount.h)