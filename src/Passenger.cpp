#include "../include/Passenger.hpp"
Passenger::Passenger(const string& passengerID, const string& username, const string& name, long long id, const string& sex, int age, const string& email, long long telNo)
    : User(username, "", Role::PASSENGER), passengerID(passengerID), name(name), id(id), sex(sex), age(age), email(email), telNo(telNo) {}
// vector<Flight> searchFlight();
// void selectSeat();
// void makePayment();  