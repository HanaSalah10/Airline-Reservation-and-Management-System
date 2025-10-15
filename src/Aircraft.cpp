#include "../include/Aircraft.hpp"

Aircraft::Aircraft(const std::string& id, const std::string& type,int numRows,int seatsPerRow,bool isAvailable)
    : id(id), type(type), numRows(numRows), seatsPerRow(seatsPerRow), isAvailable(isAvailable) {}

std::vector<Seat> Aircraft::generateSeats() const {
    std::vector<Seat> seats;
    for (int row = 1; row <= numRows; ++row) { 
        for (char seat = 'A'; seat < 'A' + seatsPerRow; ++seat) {
            seats.emplace_back(std::to_string(row) + seat);
        }
    }
    return seats;
}

void Aircraft::displayInfo() const {
    std::cout << "Aircraft Type: " << type << std::endl;
    std::cout << "Number of Rows: " << numRows << std::endl;
    std::cout << "Seats Per Row: " << seatsPerRow << std::endl;
    std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
}   