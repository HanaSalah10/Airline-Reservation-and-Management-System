#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <Seat.hpp>
class Aircraft {
private:
    std::string id;
    std::string type;
    int numRows;
    int seatsPerRow; 
    bool isAvailable;
    std::vector<std::pair<std::string, std::string>> maintenanceRecords; // Pair of start and end date-times

public:
    Aircraft(const std::string& id, const std::string& type, int numRows, int seatsPerRow,bool isAvailable = true);
    void setType(const std::string& type) { this->type = type; };
    std::string getType() const {return type;};

    std::string getID() const {return id;};

    void setNumberOfRows(int numRows) {this->numRows = numRows;};
    int getNumberOfRows() const {return numRows;};
    void setSeatsPerRow(int seatsPerRow) {this->seatsPerRow = seatsPerRow;};
    int getSeatsPerRow() const {return seatsPerRow;};

    void setAvailability(bool availability) {isAvailable = availability;};
    bool getIsAvailable() const{return isAvailable;};

    //void addMaintenancePeriod(const std::string& startDateTime, const std::string& endDateTime);
    //bool isUnderMaintenance(const std::string& dateTime) const;

    std::vector<Seat> generateSeats() const;

    void displayInfo() const ;
};
#endif // AIRCRAFT_HPP