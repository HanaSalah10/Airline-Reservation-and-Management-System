#ifndef CREDITCARDPAYMENT_HPP
#define CREDITCARDPAYMENT_HPP
#include <iostream>
#include <string>
#include "Payment.hpp"
class CreditCardPayment : public Payment {
    private:
        // Additional attributes specific to credit card payments can be added here
        std::string cardNumber;
        std::string cardHolderName;
        std::string expiryDate;
        std::string cvv;

    public:
    CreditCardPayment(double amount,
                      const std::string& cardNumber, const std::string& cardHolderName,
                      const std::string& expiryDate, const std::string& cvv)
        : Payment(amount), cardNumber(cardNumber), cardHolderName(cardHolderName),
          expiryDate(expiryDate), cvv(cvv) {}
    bool processPayment() override {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
        // Simulate payment processing logic here
        std::cout << "Credit card payment processed successfully." << std::endl;
        return true; // Assume payment is always successful for this example
    }




};
#endif // CREDITCARDPAYMENT_HPP