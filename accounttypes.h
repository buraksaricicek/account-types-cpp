#ifndef ACCOUNTTYPES_H
#define ACCOUNTTYPES_H
    
#include <iostream>
#include <string>
using namespace std;

class account {
private:
    string owner;
    float balance;
    float withdrawfee;
   
public:
    account(string name, float fee);
    void write(ostream & out) const;
    void deposit(float amount);
    bool withdraw(float amount);
    float getbalance(void) const;
    float getwithdrawfee(void) const;
};

class savingsaccount :public account {
private:
    float interestrate;

public:
    savingsaccount(string name, float fee, float rate);
    void write(ostream & out) const;
    void addinterest(void);
};

class chequingaccount : public account {
private:
    int remainingfreewithdrawals;

public:
    chequingaccount(string name, float fee, int numberfree);
    void write(ostream & out) const;
    bool withdraw(float amount);
};

#endif /* ACCOUNTTYPES_H */
