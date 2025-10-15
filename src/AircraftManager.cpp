/**
 * @file AircraftManager.cpp
 * @author Hana Salah (hanasalah566@gmail.com)
 * @brief AircraftManager class implementation  
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 */ 

#include "../include/AircraftManager.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
AircraftManager::AircraftManager(std::string filename) {
    loadAircraftData(filename);
}
void AircraftManager::loadAircraftData(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, type;
        int numRows, seatsPerRow;
        string status;
        bool isAvailable;

        getline(ss, id, ',');
        getline(ss, type, ',');
        ss >> numRows;
        ss.ignore(); // Ignore the comma
        ss >> seatsPerRow;
        ss.ignore(); // Ignore the comma
        getline(ss, status); // Read until end of line
        isAvailable = (status == "Active" || status == "active" || status == "AVAILABLE" || status == "available");
        aircrafts.push_back(Aircraft(id, type, numRows, seatsPerRow, isAvailable));
    }
    file.close();
}
Aircraft* AircraftManager::getAircraftById(const std::string& id) {
    for (auto& aircraft : aircrafts) {
        if (aircraft.getID() == id) {
            return &aircraft;
        }
    }
    return nullptr; // Not found
}