#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "../include/User.hpp"
#include "../include/Flight.hpp"
class Passenger : public User
{
    private:
    string name;
    int id;
    string sex;
    int age;
    string email;
    int telNo;

    public:
    vector<Flight> searchFlight();
    void selectSeat();
    void makePayment();

};
#endif // PASSENGER_HPP