#ifndef AIRCRAFTMANAGER_HPP
#define AIRCRAFTMANAGER_HPP

#include "Aircraft.hpp"
#include <vector>
#include <iostream>
class AircraftManager
{
    private:
        std::vector<Aircraft> aircrafts; // Assuming Aircraft is a predefined class
    public:
        AircraftManager(std::string filename = "database/aircrafts.txt");
        // Data persistence
        void loadAircraftData(const std::string& filename = "database/aircrafts.txt");
        //void saveAircraftData(const std::string& filename = "database/aircrafts.txt");
        // void addAircraft();
        // void updateAircraft();
        // void deleteAircraft();
        // void viewAllAircrafts();
        Aircraft* getAircraftById(const std::string& id);
        std::vector<Aircraft>& getAllAircrafts() { return aircrafts; }
        // Aircraft* getAircraftByType(const std::string& type);
};
#endif // AIRCRAFTMANAGER_HPP