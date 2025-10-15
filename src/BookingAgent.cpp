#include "BookingAgent.hpp"

BookingAgent::BookingAgent(BookingSystem& bookingSystem)
    : User("", "", Role::BOOKING_AGENT), bookingSystem(bookingSystem) {}

void BookingAgent::searchFlights() {
    bookingSystem.searchFlights();
}

void BookingAgent::bookFlight() {
    bookingSystem.bookFlight();
}

void BookingAgent::modifyReservation() {
    bookingSystem.modifyReservation();
}

void BookingAgent::cancelReservation() {
    bookingSystem.cancelReservation();
}
