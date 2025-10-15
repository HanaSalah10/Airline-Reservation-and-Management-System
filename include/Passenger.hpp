#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "User.hpp"
#include "Flight.hpp"

// Forward declaration
class BookingSystem;

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
    Passenger();
    Passenger(const string& passengerID, const string& username, const string& name, long long id, const string& sex, int age, const string& email, long long telNo);
    virtual ~Passenger() = default;  // Add virtual destructor
    string getPassengerID() const { return passengerID; }
    string getName() const { return name; }
    long long getId() const { return id; }
    string getSex() const { return sex; }
    int getAge() const { return age; }
    string getEmail() const { return email; }
    long long getTelNo() const { return telNo; }
    
    void passengerMenu()
    {
        std::cout << "1. Search Flights" << std::endl;
        std::cout << "2. View Reservations" << std::endl;
        std::cout<< "3. Check In" << std::endl;
        std::cout << "4. Logout" << std::endl;
    }
    void searchFlights(BookingSystem& bookingSystem);
    void viewReservations(BookingSystem& bookingSystem);
    // void checkIn();

};
#endif // PASSENGER_HPP