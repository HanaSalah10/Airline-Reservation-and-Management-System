#include "../include/Flight.hpp"
#include <iostream>
using namespace std;
Flight::Flight(const string& flightNumber, const string& origin, const string& destination,
               const string& departureDateTime, const string& arrivalDateTime,  Aircraft* aircraft, FlightStatus status)
    : flightNumber(flightNumber), origin(origin), destination(destination),
        departureDateTime(departureDateTime), arrivalDateTime(arrivalDateTime),
        aircraft(aircraft), status(status) {}
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
    aircraft->displayInfo();
}
