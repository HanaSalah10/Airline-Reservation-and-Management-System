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

class BookingSystem {
public:
    // Constructor that takes shared FlightManager
    BookingSystem(std::shared_ptr<FlightManager> fm, std::shared_ptr<PassengerManager> pm) ;
    
    // void userLogin();
    // void userRegistration();
    void searchFlights();
    void bookFlight();
    void makePayment();
    void confirmBooking();
    void cancelReservation();
    void modifyReservation();

private:
    std::vector<Reservation> reservations;
    std::shared_ptr<FlightManager> flightManager;
    std::shared_ptr<PassengerManager> passengerManager;

};

#endif // BOOKING_SYSTEM_HPP