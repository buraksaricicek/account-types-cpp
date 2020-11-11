#include "accounttypes.h"

///////////////////// implementation of account ///////////////////////
account::account(string name, float fee)
{
    owner = name;
    balance = 0;
    withdrawfee = fee;
}

void account::write(ostream & out) const
{
    out << "owner: " << owner << endl;
    out << "balance: " << balance << endl;
    out << "withdrawfee " << withdrawfee << endl;
}

void account::deposit(float amount)
{
    balance = balance + amount;
}

bool account::withdraw(float amount)
{
    bool result;
    if (amount > balance-withdrawfee) {
        cout << "Insufficient funds";
        result = false;
    } else {
        balance = balance - amount - withdrawfee;
        result = true;
    }

    return result;
}

float account::getbalance(void) const
{
    return balance;
}

float account::getwithdrawfee(void) const
{
    return withdrawfee;
}

///////////////////// implementation of savingsaccount ///////////////////////
savingsaccount :: savingsaccount(string name, float fee, float rate) : account(name, fee){
    interestrate= rate;
}
void savingsaccount :: write(ostream & out) const{
    account::write(out);
    out<<"interest rate: "<<interestrate<<endl;
    
    
}
void savingsaccount :: addinterest(void){
    account::deposit(interestrate* account::getbalance());
}




///////////////////// implementation of chequingaccount ///////////////////////
chequingaccount::chequingaccount(string name, float fee, int numberfree) : account(name,fee){
    remainingfreewithdrawals=numberfree;
    
}
void chequingaccount::write(ostream &out)const{
    account::write(out);
    out<<"remaining free withdrawals: "<<remainingfreewithdrawals<<endl;
}
bool chequingaccount::withdraw(float amount){
    
        bool result;

        if (amount > account::getbalance()-account::getwithdrawfee()) {
            result = false;
        } else {
        if(remainingfreewithdrawals == 0){
            account::withdraw(amount);
        } else {
            account::withdraw(amount-account::getwithdrawfee());
            remainingfreewithdrawals--;
    }
        
            result = true;
        }
        return result;
    }
