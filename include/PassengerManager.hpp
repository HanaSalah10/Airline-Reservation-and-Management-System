#ifndef PASSENGERMANAGER_HPP
#define PASSENGERMANAGER_HPP
#include <iostream>
#include <vector>
#include <string>

#include "Passenger.hpp"

using namespace std;

class PassengerManager
{
    private:
    vector<Passenger> passengers;


    public:
    PassengerManager();
    PassengerManager(const string& filename);
    ~PassengerManager();
    
    void loadPassengers(const string& filename = "database/passengers.txt");
    void savePassengers(const string& filename = "database/passengers.txt");
    vector<Passenger>& getAllPassengers() { return passengers; }
    void addPassenger(const Passenger& passenger);
    void removePassenger(const string& passengerID);
    Passenger* findPassenger(const string& passengerID);
    Passenger* findPassengerByUsername(const string& username);
};

#endif // PASSENGERMANAGER_HPP