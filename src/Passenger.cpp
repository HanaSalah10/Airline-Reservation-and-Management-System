#include "Passenger.hpp"
#include "BookingSystem.hpp"

Passenger::Passenger(const string& passengerID, const string& username, const string& name, long long id, const string& sex, int age, const string& email, long long telNo)
    : User(username, "", Role::PASSENGER), passengerID(passengerID), name(name), id(id), sex(sex), age(age), email(email), telNo(telNo) {}

Passenger::Passenger()
    : User("", "", Role::PASSENGER), passengerID(""), name(""), id(0), sex(""), age(0), email(""), telNo(0) {}

void Passenger::searchFlights(BookingSystem& bookingSystem)
{
    std::cout << "Searching flights..." << std::endl;
    bookingSystem.searchFlights();
    cout<<"Enter the Flight Number you wish to book (or '0' to cancel): ";
    string flightNumber;
    cin >> flightNumber;
    if (flightNumber == "0") {
        cout << "Booking canceled." << endl;
        return;
    }
    bookingSystem.bookPassengerFlight(this, flightNumber);
}

void Passenger::viewReservations(BookingSystem& bookingSystem)
{
    std::cout << "Viewing reservations..." << std::endl;
    bookingSystem.getMyReservations(passengerID);
}
// void Passenger::checkIn()  