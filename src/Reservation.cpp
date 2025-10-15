#include "Reservation.hpp"
#include "Passenger.hpp"
#include <iostream>

Reservation::Reservation(Flight* flight, Passenger* passenger, Payment* payment)
    : flight(flight), passenger(passenger), payment(payment),confirmed(false) {
    // Generate a simple reservation ID (in a real system, this should be more robust)
    reservationID = "RES" + std::to_string(rand() % 10000);
}
bool Reservation::confirm() {
    if (flight && passenger && payment) {
        confirmed = true;
        return true;
    }
    return false;
}
void Reservation::displayReservationDetails() const {

    std::cout << "Reservation ID: " << reservationID << std::endl;
    std::cout << "Passenger: " << passenger->getName() << std::endl;
    flight->displayFlightInfo();
}

Reservation::~Reservation() {
    // Destructor - no dynamic memory management needed since we're using pointers
    // The actual objects are managed elsewhere
}
