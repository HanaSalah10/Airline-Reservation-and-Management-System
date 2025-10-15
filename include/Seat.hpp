#ifndef SEAT_HPP
#define SEAT_HPP
#include <string>
class Seat
{

private:
    std::string seatNumber;
    bool isBooked;

public:
    Seat(const std::string& seatNumber)
        : seatNumber(seatNumber), isBooked(false) {}

    // Getters
    std::string getSeatNumber() const { return seatNumber; }
    bool getIsBooked() const { return isBooked; }

    // Setters
    void setSeatNumber(const std::string& seatNumber) { this->seatNumber = seatNumber; }
    void setIsBooked(bool isBooked) { this->isBooked = isBooked; }

    // Booking methods
    bool book() {
        if (!isBooked) {
            isBooked = true;
            return true; // Booking successful
        }
        return false; // Seat already booked
    }
    bool cancel() {
        if (isBooked) {
            isBooked = false;
            return true; // Cancellation successful
        }
        return false; // Seat was not booked
    }
    // Display method
    void display() const {
        std::cout << "Seat Number: " << seatNumber
                  << ", Status: " << (isBooked ? "Booked" : "Available") <<
                    std::endl;
    }
};

#endif // SEAT_HPP