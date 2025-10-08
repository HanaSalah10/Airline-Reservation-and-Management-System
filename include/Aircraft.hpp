#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include <string>
#include <iostream>
class Aircraft {
private:
    std::string id;
    std::string type;
    int numberOfSeats; 
    bool isAvailable;
    std::vector<std::pair<std::string, std::string>> maintenanceRecords; // Pair of start and end date-times

public:
    Aircraft(const std::string& id, const std::string& type, int numberOfSeats);
    void setType(const std::string& type) { this->type = type; };
    std::string getType() const {return type;};
    std::string getID() const {return id;};
    void setNumberOfSeats(int numberOfSeats) {this->numberOfSeats = numberOfSeats;};
    int getNumberOfSeats() const {return numberOfSeats;};
    void setAvailability(bool availability) {isAvailable = availability;};
    bool getIsAvailable() const{return isAvailable;};

    //void addMaintenancePeriod(const std::string& startDateTime, const std::string& endDateTime);
    //bool isUnderMaintenance(const std::string& dateTime) const;

    void displayInfo() const ;
};
#endif // AIRCRAFT_HPP