#ifndef CASHPAYMENT_HPP
#define CASHPAYMENT_HPP
#include <iostream>
#include <string>
#include "Payment.hpp"
class CashPayment : public Payment {
    private:
        // Additional attributes specific to cash payments can be added here
        std::string cashierName;

    public:
    CashPayment(double amount, const std::string& cashierName)
        : Payment(amount), cashierName(cashierName) {}
    bool processPayment() override {
        std::cout << "Processing cash payment of $" << amount << std::endl;
        // Simulate payment processing logic here
        std::cout << "Cash payment processed successfully." << std::endl;
        return true; // Assume payment is always successful for this example
    }

};
#endif // CASHPAYMENT_HPP