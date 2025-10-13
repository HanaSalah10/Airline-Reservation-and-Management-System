#include "../include/Aircraft.hpp"

Aircraft::Aircraft(const std::string& id, const std::string& type, int numberOfSeats,bool isAvailable)
    : id(id), type(type), numberOfSeats(numberOfSeats), isAvailable(isAvailable) {}

void Aircraft::displayInfo() const {
    std::cout << "Aircraft Type: " << type << std::endl;
    std::cout << "Number of Seats: " << numberOfSeats << std::endl;
    std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
}   