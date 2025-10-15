#ifndef FLIGHTMANAGER_HPP
#define FLIGHTMANAGER_HPP
#include <vector>
#include <unordered_set>
#include "Flight.hpp"
#include "AircraftManager.hpp"
#include "CrewManager.hpp"
using namespace std;
class FlightManager{
    private:
    std::vector<Flight> flights;
    std::unordered_set<std::string> flightNumbers; // To ensure unique flight numbers
    AircraftManager& aircraftManager;
    CrewManager& crewManager;
    public:
    FlightManager(AircraftManager& aircraftManager, CrewManager& crewManager, const std::string& filename = "database/flights.txt");
    
    // Data persistence
    void loadFlightData(const std::string& filename = "database/flights.txt");
    void saveFlightData(const std::string& filename = "database/flights.txt");
    // Flight management
    void addFlight();
    void updateFlightDetails(const std::string& flightNumber);
    void updateFlightCrew(const std::string& flightNumber);
    void updateFlightStatus(const std::string& flightNumber);
    void removeFlight();

    void viewAllFlights();

    void assignPilot();
    void assignFlightAttendants();
    void assignCrewToFlight(Flight& flight);
    Flight* searchFlight(const std::string& flightNumber);
};
#endif // FLIGHTMANAGER_HPP