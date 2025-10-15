#ifndef PAYPALPAYMENT_HPP
#define PAYPALPAYMENT_HPP
#include <iostream>
#include <string>
#include "Payment.hpp"
class PayPalPayment : public Payment {
    private:
        // Additional attributes specific to PayPal payments can be added here
        std::string email;
        std::string password;

    public:
    PayPalPayment(double amount, const std::string& email, const std::string& password)
        : Payment(amount), email(email), password(password) {}
    bool processPayment() override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
        // Simulate payment processing logic here
        std::cout << "PayPal payment processed successfully." << std::endl;
        return true; // Assume payment is always successful for this example
    }




};
#endif // PAYPALPAYMENT_HPP