#include "CrewManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

CrewManager::CrewManager()
{
    loadFlightAttendantdata();
    loadPilotdata();
}

void CrewManager::loadFlightAttendantdata(const std::string& filename)
{
   ifstream file(filename);
   if (!file) {
       cerr << "Error opening file: " << filename << endl;
       return;
   }    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, contact, certification;
        int experience;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, contact, ',');
        getline(ss, certification, ',');
        ss >> experience;
        FlightAttendant fa(id, name, contact, certification, experience);
        flightAttendants.push_back(fa);
    }
    file.close();
}
void CrewManager::loadPilotdata(const std::string& filename)
{
   ifstream file(filename);
   if (!file) {
       cerr << "Error opening file: " << filename << endl;
       return;
   }    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, contact, license;
        int hours;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, contact, ',');
        getline(ss, license, ',');
        ss >> hours;
        Pilot pilot(id, name, contact, license, hours);
        pilots.push_back(pilot);
    }
    file.close();
}
Pilot* CrewManager::findAvailablePilot(const std::string& aircraftType) {
    (void)aircraftType;  // Mark as unused to suppress warning
    for (auto& pilot : pilots) {
        if (pilot.getAvailability() /*&& pilot.isCertifiedFor(aircraftType)*/) {
            return &pilot;
        }
    }
    return nullptr; // No available pilot found
}
FlightAttendant* CrewManager::findAvailableFlightAttendant() {
    for (auto& fa : flightAttendants) {
        if (fa.getAvailability()) {
            return &fa;
        }
    }
    return nullptr; // No available flight attendant found
}
void CrewManager::displayAllPilots() const {
    if (pilots.empty()) {
        cout << "No pilots available." << endl;
        return;
    }
    for (const auto& pilot : pilots) {  
        pilot.displayInfo();
    }
}
void CrewManager::displayAllFlightAttendants() const {
    if (flightAttendants.empty()) {
        cout << "No flight attendants available." << endl;
        return;
    }
    for (const auto& fa : flightAttendants) {  
        fa.displayInfo();

    }   

}
