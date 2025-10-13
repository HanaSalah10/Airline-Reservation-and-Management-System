#include "../include/Pilot.hpp"

Pilot::Pilot(const std::string& id, const std::string& name, const std::string& contact,
             const std::string& license, int hours)
    : Crew(id, name, contact), licenseNumber(license), flightHours(hours) {}

// void Pilot::addCertification(const std::string& aircraftType) {
//     certifiedAircraftTypes.push_back(aircraftType);
// }
// bool Pilot::isCertifiedFor(const std::string& aircraftType) const {
//     return std::find(certifiedAircraftTypes.begin(), certifiedAircraftTypes.end(),
//                     aircraftType) != certifiedAircraftTypes.end();
// }
void Pilot::displayInfo() const {
    std::cout << "Pilot ID: " << id << ", Name: " << name 
              << ", License: " << licenseNumber 
              << ", Flight Hours: " << flightHours << std::endl;
}