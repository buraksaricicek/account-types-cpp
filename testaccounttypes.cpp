#include "accounttypes.h"


int main(void)
{
    savingsaccount s("joe", 0.50, 0.02);
    chequingaccount c("bob", 0.50, 2);

    s.deposit(100.);
    c.deposit(100.);

    cout << "savings account: " << endl;
    s.write(cout);
    cout << endl << "chequing account: " << endl;
    c.write(cout);
   
    s.withdraw(10.);
    s.withdraw(5.);
    s.withdraw(20.0);
    s.addinterest();

    cout << endl << "savings account: " << endl;
    s.write(cout);

    c.withdraw(10.);
    c.withdraw(5.);
    c.withdraw(20.0);

    cout << endl << "chequing account: " << endl;
    c.write(cout);

   return 0;
}

