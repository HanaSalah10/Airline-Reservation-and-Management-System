#include "FlightAttendant.hpp"
FlightAttendant::FlightAttendant(const std::string& id, const std::string& name, 
                   const std::string& contact, const std::string& certification, 
                   int experience)
    : Crew(id, name, contact), certificationLevel(certification), 
      yearsOfExperience(experience) {}
void FlightAttendant::addLanguage(const std::string& language) {
    languages.push_back(language);
}
void FlightAttendant::displayInfo() const {
    std::cout << "Flight Attendant ID: " << id << ", Name: "
                << name << ", Certification: " << certificationLevel 
                << ", Experience: " << yearsOfExperience << " years" << std::endl;
}
