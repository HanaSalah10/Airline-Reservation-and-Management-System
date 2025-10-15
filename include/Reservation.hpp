#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
#include "Flight.hpp"
#include "Payment.hpp"

// Forward declaration
class Passenger;

class Reservation {
public:
    Reservation(Flight* flight, Passenger* passenger, Payment* payment);
    bool confirm();
    void displayReservationDetails() const;
    std::string getReservationID() const { return reservationID; }
    Flight* getFlight() const { return flight; }
    Passenger* getPassenger() const { return passenger; }
    Payment* getPayment() const { return payment; }
    bool isConfirmed() const { return confirmed; }
    ~Reservation();

private:
    std::string reservationID;
    Flight *flight=nullptr;
    Passenger *passenger=nullptr;
    Payment *payment=nullptr;
    bool confirmed;
};

#endif // RESERVATION_HPP