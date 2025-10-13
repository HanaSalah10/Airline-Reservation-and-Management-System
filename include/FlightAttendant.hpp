#ifndef FLIGHT_ATTENDANT_HPP
#define FLIGHT_ATTENDANT_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Crew.hpp"
class FlightAttendant : public Crew {
private:
    std::string certificationLevel;
    std::vector<std::string> languages;
    int yearsOfExperience;
    
public:
    FlightAttendant(const std::string& id, const std::string& name, 
                   const std::string& contact, const std::string& certification, 
                   int experience);
    
    void addLanguage(const std::string& language);
    
    void displayInfo() const override;
    
    // Getters
    std::string getCertificationLevel() const { return certificationLevel; }
    int getExperience() const { return yearsOfExperience; }
};
#endif // FLIGHT_ATTENDANT_HPP