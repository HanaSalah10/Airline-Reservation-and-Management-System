#ifndef BOOKING_SYSTEM_HPP
#define BOOKING_SYSTEM_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "User.hpp"
#include "Flight.hpp"
#include "Reservation.hpp"
#include "FlightManager.hpp"
#include "PassengerManager.hpp"
#include "Payment.hpp"

class BookingSystem {
public:
    // Constructor that takes shared FlightManager
    BookingSystem(std::shared_ptr<FlightManager> fm, std::shared_ptr<PassengerManager> pm) ;
    
    // void userLogin();
    // void userRegistration();
    void searchFlights();
    void bookFlight();
    void bookPassengerFlight(Passenger* passenger, std::string flightNumber);
    Payment* makePayment(double amount);
    void getMyReservations(std::string passengerID);
    void confirmBooking();
    void cancelReservation();
    void modifyReservation();

private:
    std::vector<Reservation> reservations;
    std::shared_ptr<FlightManager> flightManager;
    std::shared_ptr<PassengerManager> passengerManager;

};

#endif // BOOKING_SYSTEM_HPP