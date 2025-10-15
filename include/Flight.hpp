#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include "Aircraft.hpp"
#include "Pilot.hpp"
#include "FlightAttendant.hpp"
#include "Seat.hpp"
using namespace std;
enum FlightStatus { SCHEDULED, DELAYED, CANCELLED, COMPLETED };
class Flight{
    private:
    string flightNumber;
    string origin;
    string destination;
    string departureDateTime;  // "2023-12-15 08:30"
    string arrivalDateTime;    // "2023-12-15 12:45"
    Aircraft* aircraft = nullptr;
    FlightStatus status;
    Pilot *assignedPilot = nullptr;
    vector<FlightAttendant*> assignedFlightAttendants;
    vector<Seat> seats; // Seats in the flight
    double price; // Price per seat


    public:
    Flight(const string& flightNumber, const string& origin, const string& destination,
           const string& departureDateTime, const string& arrivalDateTime, Aircraft* aircraft, FlightStatus status, double price = 100.0);
    void setFlightNumber(const string& flightNumber);
    string getFlightNumber() const;
    void setOrigin(const string& origin);
    string getOrigin() const;
    void setDestination(const string& destination);
    string getDestination() const;
    void setDepartureDateTime(const string& departureDateTime);
    string getDepartureDateTime() const;
    void setArrivalDateTime(const string& arrivalDateTime);
    string getArrivalDateTime() const;
    void setAircraft(Aircraft* aircraft);
    Aircraft* getAircraft() const;
    void setStatus(FlightStatus status);
    FlightStatus getStatus() const;
    void setPrice(double price) { this->price = price; }
    double getPrice() const { return price; }
    
    // Pilot management methods
    void assignPilot(Pilot* pilot);
    Pilot* getAssignedPilot() const;
    
    // Flight Attendant management methods
    void assignFlightAttendant(FlightAttendant* attendant);
    void removeFlightAttendant(FlightAttendant* attendant);
    vector<FlightAttendant*> getAssignedFlightAttendants() const;
    int getFlightAttendantCount() const;

    //booking management methods
    bool bookSeat(const string& seatNumber);
    bool cancelSeat(const string& seatNumber);
    
    void displayAllAvailableSeats() const;
    void displayFlightInfo() const;
    ~Flight();

};
#endif // FLIGHT_HPP