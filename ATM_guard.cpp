// OOPS Project
#include <iostream>
#include <string>
using namespace std;

/* ATM Interface */
class ATM
{
public:
    /*pure virtual functions: Abstraction*/
    virtual bool debit(double amount, int enteredPin) = 0;
    virtual void credit(double amount) = 0;
    virtual void printSlip() = 0;
    virtual bool changePin(int oldPin, int newPin) = 0;
    virtual double checkBalance() = 0;
};

/* Abstract/virtual Account Class: Inheritance */
class Account : public ATM
{
public:
    double balance;
    string accNo;
    string custName;

private:
    int pin; /*data hiding*/

public:
    /*Encapsulation*/
    int getPin()
    {
        return pin;
    }

    void setPin(int pin)
    {
        this->pin = pin;
    }

    /*functions*/
    void printSlip()
    {
        cout << "Name: " << custName << endl;
        cout << " current Balance: " << balance << endl;
    }

    bool changePin(int oldPin, int newPin)
    {
        if (this->pin == oldPin)
        {
            this->pin = newPin;
            cout << "Pin changed successfully" << endl;
            return true;
        }
        else
        {
            cout << "Invalid old pin" << endl;
            return false;
        }
    }

    double checkBalance()
    {
        return this->balance;
    }

    void credit(double amount)
    {
        this->balance += amount;
        cout << " Amount Credited successfully ! \n Updated Balance = " << this->checkBalance() << endl;
    }

    /*Polymorphism*/
    bool debit(double amount, int enteredPin) override
    {
        if (this->pin == enteredPin)
        {

            if (balance >= amount)
            {

                balance -= amount;

                balance -= 5; // transaction fee

                cout << "Debit successful" << endl;
                cout << "Remaining Balance = " << this->checkBalance() << endl;
                return true;
            }
            else
            {
                cout << "Insufficient balance! " << endl;
                return false;
            }
        }
        else
        {
            cout << " Wrong pin entered , check pin";
        }
    }
};

int main()
{

    Account sa;

    sa.custName = "John cena";
    sa.balance = 0;

    sa.setPin(1234);

    cout << "Updated pin = " << sa.getPin() << endl;
    int choice;

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Credit Money\n";
        cout << "3. Debit Money\n";
        cout << "4. Change PIN\n";
        cout << "5. printSlip\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " Current balance is : " << sa.checkBalance();
            break;

        case 2:
            double am1;
            cout << "Enter amount to credit : ";
            cin >> am1;
            sa.credit(am1);
            break;

        case 3:
            int p;
            double am2;
            cout << "Enter pin and amount to debit: ";
            cin >> p;
            cin >> am2;
            sa.debit(am2, p);
            break;

        case 4:
            int oldPin, newPin;
            cout << "Enter old PIN and New Pin: ";
            cin >> oldPin;
            cin >> newPin;
            sa.changePin(oldPin, newPin);
            break;

        case 5:
            cout << " Current balance is : ";
            sa.printSlip();

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    while (choice != 0);

    return 0;
}