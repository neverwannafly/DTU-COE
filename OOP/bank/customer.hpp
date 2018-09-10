#ifndef customer_hpp
#define customer_hpp

#include "transaction.hpp"
#include <vector>
#define MAX_DEV 999999
#define MIN_DEV 100000

void initSeed() {
    srand((int)time(0));
}

class Customer {
public:
    Customer();
    void withdraw(double amount);
    void deposit(double amount);
    bool login(long passcode);
    ~Customer();
private:

    bool loginStatus;
    long accountNumber;
    long passcode;
    std::string name;
    double accountBalance;
    std::vector<Transaction> transactions;
};

#endif