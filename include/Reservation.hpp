#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
#include "Flight.hpp"
#include "Passenger.hpp"

class Reservation {
public:
    Reservation(Flight* flight, Passenger* passenger);
    void displayReservationDetails() const;

private:
    std::string reservationID;
    Flight *flight=nullptr;
    Passenger *passenger=nullptr;
};

#endif // RESERVATION_HPP