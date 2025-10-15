#ifndef BOOKINGAGENT_HPP
#define BOOKINGAGENT_HPP

#include <iostream>
#include <vector>
#include <string>
#include "User.hpp"
#include "BookingSystem.hpp"

class BookingAgent : public User {
public:
    BookingAgent(BookingSystem& bookingSystem);
    void searchFlights();
    void bookFlight();
    void modifyReservation();
    void cancelReservation();
    //void viewBookings();
    void bookingAgentMenu()
    {
        std::cout << "1. Search Flights" << std::endl;
        std::cout << "2. Book Flight" << std::endl;
        std::cout << "3. Modify Reservation" << std::endl;
        std::cout << "4. Cancel Reservation" << std::endl;
        std::cout << "5. Logout" << std::endl;
    }


private:
    BookingSystem& bookingSystem;
    std::vector<Flight> bookedFlights;
};
#endif // BOOKINGAGENT_HPP