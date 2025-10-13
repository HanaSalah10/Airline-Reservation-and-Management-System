#ifndef CREWMANAGER_HPP
#define CREWMANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Pilot.hpp"
#include "FlightAttendant.hpp"

class CrewManager {
private:
    std::vector<Pilot> pilots;
    std::vector<FlightAttendant> flightAttendants;
    
public:
    CrewManager();
    void loadPilotdata(const std::string& filename = "database/pilots.txt");
    void loadFlightAttendantdata(const std::string& filename = "database/flightAttendants.txt");
    void addPilot(const Pilot& pilot) { pilots.push_back(pilot); }
    void addFlightAttendant(const FlightAttendant& fa) { flightAttendants.push_back(fa); }
    
    Pilot* findAvailablePilot(const std::string& aircraftType);
    
    FlightAttendant* findAvailableFlightAttendant();
    
    void displayAllPilots() const ;

    void displayAllFlightAttendants() const ;

    std::vector<Pilot>& getPilots() { return pilots; }
    std::vector<FlightAttendant>& getFlightAttendants() { return flightAttendants; }



    ~CrewManager() {}
};
#endif // CREWMANAGER_HPP