#include "../include/Reservation.hpp"
#include <iostream>
Reservation::Reservation(Flight* flight, Passenger* passenger)
    : flight(flight), passenger(passenger) {
    // Generate a simple reservation ID (in a real system, this should be more robust)
    reservationID = "RES" + std::to_string(rand() % 10000);
}
void Reservation::displayReservationDetails() const {
    std::cout << "Reservation ID: " << reservationID << std::endl;
    std::cout << "Passenger: " << passenger->getName() << std::endl;
    flight->displayFlightInfo();
}
