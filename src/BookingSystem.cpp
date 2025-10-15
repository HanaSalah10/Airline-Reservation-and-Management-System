#include "../include/BookingSystem.hpp"
#include <iostream>

BookingSystem::BookingSystem(std::shared_ptr<FlightManager> fm, std::shared_ptr<PassengerManager> pm) 
    : flightManager(fm), passengerManager(pm) {
}

void BookingSystem::searchFlights() {
    if (flightManager) {
            flightManager->viewAllFlights();
    } else {
        std::cout << "FlightManager not available!" << std::endl;
    }
}

void BookingSystem::bookFlight() {
    if (flightManager) {
        flightManager->viewAllFlights();
        std::string passengerID;
        std::cout << "Enter Passenger ID: ";
        std::cin >> passengerID;
        std::string flightNumber;
        std::cout << "Enter Flight Number to book: ";
        std::cin >> flightNumber;

        Flight* flight = flightManager->searchFlight(flightNumber);
        if (!flight) {
            std::cout << "Flight not found!" << std::endl;
            return;
        }
        flight->displayAllAvailableSeats();
        std::string seatNumber;
        std::cout << "Enter Seat Number to book: ";
        std::cin >> seatNumber;
        if (flight->bookSeat(seatNumber)) {
            // Assuming passengerManager can provide a Passenger object based on passengerID
            Passenger* user = passengerManager->findPassenger(passengerID);
            if(!user) {
                std::cout << "Passenger not found!" << std::endl;
                return;
            } 
            Reservation* reservation = new Reservation(flight, user);
            reservations.push_back(*reservation);
            std::cout << "Reservation created successfully!" << std::endl;
            delete reservation;  // Free the memory allocated for the reservation
            
        } else {
            std::cout << "Failed to book seat. It may already be booked." << std::endl;
        }

    } else {
        std::cout << "FlightManager not available!" << std::endl;
    }
}
void BookingSystem::confirmBooking() {
    std::cout << "Confirming booking..." << std::endl;
    // Implementation for confirmation logic
}
void BookingSystem::cancelReservation() {
    std::cout << "Canceling reservation..." << std::endl;
    // Implementation for cancellation logic
}

void BookingSystem::modifyReservation() {
    std::cout << "Modifying reservation..." << std::endl;
    // Implementation for modification logic
}  