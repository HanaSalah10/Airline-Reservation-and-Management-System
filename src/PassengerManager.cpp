#include "PassengerManager.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
PassengerManager::PassengerManager(const string& filename) {
    loadPassengers(filename);
}
PassengerManager::PassengerManager() {
    loadPassengers();
}
PassengerManager::~PassengerManager() {
    // Destructor logic if needed
}
void PassengerManager::loadPassengers(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string passengerID, username, name, idStr, sex, ageStr, email, telNoStr;
        long long idNum, telNo;
        int age;
        getline(ss, passengerID, ',');
        getline(ss, username, ',');
        getline(ss, name, ',');
        getline(ss, idStr, ',');
        getline(ss, sex, ',');
        getline(ss, ageStr, ',');
        getline(ss, email, ',');
        getline(ss, telNoStr, ',');
        idNum = stoll(idStr);
        age = stoi(ageStr);
        telNo = stoll(telNoStr);
        Passenger passenger(passengerID, username, name, idNum, sex, age, email, telNo);
        passengers.push_back(passenger);
    }
    file.close();
}
void PassengerManager::savePassengers(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& passenger : passengers) {
        file << passenger.getPassengerID() << ","
             << passenger.getUsername() << ","
             << passenger.getName() << ","
             << passenger.getId() << ","
             << passenger.getSex() << ","
             << passenger.getAge() << ","
             << passenger.getEmail() << ","
             << passenger.getTelNo() << endl;
    }
    file.close();
}
void PassengerManager::addPassenger(const Passenger& passenger) {
    passengers.push_back(passenger);
}
void PassengerManager::removePassenger(const string& passengerID) { 
    passengers.erase(remove_if(passengers.begin(), passengers.end(),
                               [&passengerID](const Passenger& p) { return p.getPassengerID() == passengerID; }),
                     passengers.end());
}
Passenger* PassengerManager::findPassenger(const string& passengerID) {
    for (auto& passenger : passengers) {
        if (passenger.getPassengerID() == passengerID) {
            return &passenger;
        }
    }
    return nullptr; // Not found
}