#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "../include/User.hpp"
#include "../include/Flight.hpp"
class Passenger : public User
{
    private:
    string passengerID;
    string name;
    long long id;
    string sex;
    int age;
    string email;
    long long telNo;

    public:
    Passenger(const string& passengerID, const string& username, const string& name, long long id, const string& sex, int age, const string& email, long long telNo);
    string getPassengerID() const { return passengerID; }
    string getName() const { return name; }
    long long getId() const { return id; }
    string getSex() const { return sex; }
    int getAge() const { return age; }
    string getEmail() const { return email; }
    long long getTelNo() const { return telNo; }
    // vector<Flight> searchFlight();
    // void selectSeat();
    // void makePayment();

};
#endif // PASSENGER_HPP