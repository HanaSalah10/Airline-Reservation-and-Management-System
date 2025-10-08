#ifndef FLIGHTMANAGER_HPP
#define FLIGHTMANAGER_HPP
#include <vector>
#include <unordered_set>
#include "../include/Flight.hpp"
#include "../include/AircraftManager.hpp"

class FlightManager{
    private:
    std::vector<Flight> flights;
    std::unordered_set<std::string> flightNumbers; // To ensure unique flight numbers
    public:
    //FlightManager(const std::string& filename = "database/flights.txt", AircraftManager& aircraftManager = AircraftManager());
    // Data persistence
    void loadFlightData(AircraftManager& aircraftManager,const std::string& filename = "database/flights.txt");
    void saveFlightData(const std::string& filename = "database/flights.txt");
    // Flight management
    void addFlight(const Flight& flight);
    void updateFlight(const std::string& flightNumber,const Flight& flight);
    void removeFlight(const std::string& flightNumber);
    void viewAllFlights();
    void assignPilot();
    void assignFlightAttendants();
    //Flight* searchFlight(const std::string& flightNumber);
};
#endif // FLIGHTMANAGER_HPP