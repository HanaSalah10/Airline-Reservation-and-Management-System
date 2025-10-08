#include "../include/FlightManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
// FlightManager::FlightManager(const std::string& filename) {
//     loadFlightData(filename);
// }
void FlightManager::loadFlightData(AircraftManager& aircraftManager, const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraftID  , statusStr;
        int numberOfSeats;
        getline(ss, flightNumber, ',');
        getline(ss, origin, ',');
        getline(ss, destination, ',');
        getline(ss, departureDateTime, ',');
        getline(ss, arrivalDateTime, ',');
        getline(ss , aircraftID , ',');
        ss.ignore(); // Ignore the comma
        getline(ss, statusStr); // Read until end of line
       // Aircraft* aircraft = aircraftManager.getAircraftById(aircraftID);
        //aircraft->setAvailability(false); // Mark aircraft as unavailable

        // if (!aircraft) {
        //     cerr << "Aircraft with ID " << aircraftID << " not found. Skipping flight " << flightNumber << endl;
        //     continue; // Skip this flight entry
        // }
        
        FlightStatus status;
        if (statusStr == "SCHEDULED") status = SCHEDULED;
        else if (statusStr == "DELAYED") status = DELAYED;
        else if (statusStr == "CANCELLED") status = CANCELLED;
        else if (statusStr == "COMPLETED") status = COMPLETED;
        else {
            cerr << "Invalid flight status in file: " << statusStr << endl;
            continue; // Skip invalid entries
        }
        // flights.push_back(Flight(flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraft, status));
    }
    file.close();
}
void FlightManager::saveFlightData(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& flight : flights) {
        file << flight.getFlightNumber() << ","
                << flight.getOrigin() << ","
                << flight.getDestination() << ","
                << flight.getDepartureDateTime() << ","
                << flight.getArrivalDateTime() << ","
                << flight.getAircraft()->getID() << ",";
        switch (flight.getStatus()) {
            case SCHEDULED: file << "SCHEDULED"; break;
            case DELAYED: file << "DELAYED"; break;
            case CANCELLED: file << "CANCELLED"; break;
            case COMPLETED: file << "COMPLETED"; break;
        }
        file << endl;
    }
    file.close();
}
void FlightManager::addFlight(const Flight& flight) {
    flights.push_back(flight);
    cout << "Flight added successfully." << endl;
}
void FlightManager::updateFlight(const std::string& flightNumber, const Flight& flight) {
    for (auto& f : flights) {
        if (f.getFlightNumber() == flightNumber) {
            f = flight;
            cout << "Flight updated successfully." << endl;
            return;
        }
    }
    cout << "Flight not found." << endl;
}
void FlightManager::removeFlight(const std::string& flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            flights.erase(it);
            cout << "Flight removed successfully." << endl;
            return;
        }
    }
    cout << "Flight not found." << endl;
}
void FlightManager::viewAllFlights() {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    for (const auto& flight : flights) {
        flight.displayFlightInfo();
        cout << "------------------------" << endl;
    }
}
void FlightManager::assignPilot() {
    cout << "Assigning pilot to flight..." << endl;
    // Implementation would go here
}
void FlightManager::assignFlightAttendants() {
    cout << "Assigning flight attendants to flight..." << endl;
    // Implementation would go here
}   
