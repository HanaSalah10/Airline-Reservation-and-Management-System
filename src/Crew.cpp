#include "Crew.hpp"

#include <iostream>
#include <vector>

using namespace std;
Crew::Crew(const std::string& id, const std::string& name, const std::string& contact)
    : id(id), name(name), contactInfo(contact), isAvailable(true) {}  

Crew::~Crew() = default;

string Crew::getId() const { return id; }
string Crew::getName() const { return name; }
bool Crew::getAvailability() const { return isAvailable; }
void Crew::setAvailability(bool available) { isAvailable = available; }
void Crew::displayInfo() const {
    cout << "Crew ID: " << id << ", Name: " << name << ", Contact: " << contactInfo 
         << ", Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
}

