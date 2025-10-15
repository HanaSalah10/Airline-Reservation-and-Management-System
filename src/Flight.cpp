#include "Flight.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
Flight::Flight(const string& flightNumber, const string& origin, const string& destination,
               const string& departureDateTime, const string& arrivalDateTime,  Aircraft* aircraft, FlightStatus status, double price)
    : flightNumber(flightNumber), origin(origin), destination(destination),
        departureDateTime(departureDateTime), arrivalDateTime(arrivalDateTime),
        aircraft(aircraft), status(status), price(price) {
            seats = aircraft->generateSeats();
        }
void Flight::setFlightNumber(const string& flightNumber) {
    this->flightNumber = flightNumber;
}
string Flight::getFlightNumber() const {
    return flightNumber;        
}
void Flight::setOrigin(const string& origin) {
    this->origin = origin;
}
string Flight::getOrigin() const {
    return origin;
}
void Flight::setDestination(const string& destination) {
    this->destination = destination;
}
string Flight::getDestination() const {
    return destination;
}
void Flight::setDepartureDateTime(const string& departureDateTime) {
    this->departureDateTime = departureDateTime;
}
string Flight::getDepartureDateTime() const {
    return departureDateTime;
}
void Flight::setArrivalDateTime(const string& arrivalDateTime) {
    this->arrivalDateTime = arrivalDateTime;
}
string Flight::getArrivalDateTime() const {
    return arrivalDateTime;
}
void Flight::setAircraft(Aircraft* aircraft) {
    this->aircraft = aircraft;
}
Aircraft* Flight::getAircraft() const {
    return aircraft;
}
void Flight::setStatus(FlightStatus status) {

    this->status = status;
}
FlightStatus Flight::getStatus() const {
    return status;
}
void Flight::displayFlightInfo() const {
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Origin: " << origin << endl;
    cout << "Destination: " << destination << endl;     
    cout << "Departure: " << departureDateTime << endl;
    cout << "Arrival: " << arrivalDateTime << endl;
    cout << "Status: ";
    switch (status) {
        case SCHEDULED: cout << "Scheduled"; break;
        case DELAYED: cout << "Delayed"; break;
        case CANCELLED: cout << "Cancelled"; break; 
        case COMPLETED: cout << "Completed"; break;
    }
    cout << endl;
    cout << "Aircraft Info: ";
    if (aircraft) {
        cout << aircraft->getType() << " Number of Seats: " << aircraft->getNumberOfRows() * aircraft->getSeatsPerRow() << endl;
    } else {
        cout << "No aircraft assigned." << endl;
    }
    cout << "Price per seat: $" << price << endl;
}

// Pilot management methods
void Flight::assignPilot(Pilot* pilot) {
    assignedPilot = pilot;
}

Pilot* Flight::getAssignedPilot() const {
    return assignedPilot;
}

// Flight Attendant management methods
void Flight::assignFlightAttendant(FlightAttendant* attendant) {
    if (attendant != nullptr) {
        assignedFlightAttendants.push_back(attendant);
    }
}

void Flight::removeFlightAttendant(FlightAttendant* attendant) {
    auto it = find(assignedFlightAttendants.begin(), assignedFlightAttendants.end(), attendant);
    if (it != assignedFlightAttendants.end()) {
        assignedFlightAttendants.erase(it);
    }
}

vector<FlightAttendant*> Flight::getAssignedFlightAttendants() const {
    return assignedFlightAttendants;
}

int Flight::getFlightAttendantCount() const {
    return assignedFlightAttendants.size();
}
bool Flight::bookSeat(const string& seatNumber) {
    for (auto& seat : seats) {
        if (seat.getSeatNumber() == seatNumber) {
            return seat.book();
        }
    }
    return false; // Seat not found
}
bool Flight::cancelSeat(const string& seatNumber) {
    for (auto& seat : seats) {
        if (seat.getSeatNumber() == seatNumber) {
            return seat.cancel();
        }
    }
    return false; // Seat not found
}
void Flight::displayAllAvailableSeats() const {
    cout << "Available Seats for Flight " << flightNumber << ":\n";
    bool anyAvailable = false;
    for (const auto& seat : seats) {
        if (!seat.getIsBooked()) {
            seat.display();
            anyAvailable = true;
        }
    }
    if (!anyAvailable) {
        cout << "No available seats.\n";
    }
}

Flight::~Flight() {
    // No dynamic memory to free since Aircraft, Pilot, and FlightAttendants are managed elsewhere
    // Just clear the vector (pointers will be deleted by their respective managers)
    assignedFlightAttendants.clear();
}
