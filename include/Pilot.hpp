#ifndef PILOT_HPP
#define PILOT_HPP
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Crew.hpp"
class Pilot : public Crew {
private:
    std::string licenseNumber;
    int flightHours;
   // std::vector<std::string> certifiedAircraftTypes;
    
public:
    Pilot(const std::string& id, const std::string& name, const std::string& contact,
          const std::string& license, int hours);
    
    //void addCertification(const std::string& aircraftType);

   // bool isCertifiedFor(const std::string& aircraftType) const;
    void displayInfo() const override;

    // Getters
    std::string getLicenseNumber() const { return licenseNumber; }
    int getFlightHours() const { return flightHours; }
};
#endif 