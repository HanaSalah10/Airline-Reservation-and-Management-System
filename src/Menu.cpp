#include "Menu.hpp"
#include <iostream>
using namespace std;

void Menu::displayAdminMenu() {
    cout << "Admin Menu" << endl;
    cout << "1. Manage Flights" << endl;
    cout << "2. View Reports" << endl;
    cout << "3. Logout" << endl;
}

void Menu::displayPassengerMenu() {
    cout << "Passenger Menu" << endl;
    cout << "1. Book Flight" << endl;
    cout << "2. View Booking" << endl;
    cout << "3. Cancel Booking" << endl;
    cout << "4. Logout" << endl;
}

void Menu::displayBookingAgentMenu() {
    cout << "Booking Agent Menu" << endl;
    cout << "1. Book Flight for Passenger" << endl;
    cout << "2. View Passenger Bookings" << endl;
    cout << "3. Logout" << endl;
}