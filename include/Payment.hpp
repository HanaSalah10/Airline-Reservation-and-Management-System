#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <iostream>
#include <string>

class Payment {
public:
    Payment(double amount):
        amount(amount){
        paymentID = "PAY" + std::to_string(idCounter++);
    }
    virtual bool processPayment() = 0; // Pure virtual function
    virtual void displayPaymentDetails() const {
        std::cout << "Payment ID: " << paymentID << std::endl;
        std::cout << "Amount: $" << amount << std::endl;
    }
    double getAmount() const { return amount; }
   
    virtual ~Payment() {}
private:
    static int idCounter;

protected:
    std::string paymentID;
    double amount;
};

#endif // PAYMENT_HPP