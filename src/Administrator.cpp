#include "../include/Administrator.hpp"
#include <iostream>

using namespace std;
void Administrator::createUserAccount(UserManager& userManager) {
    cout << "Creating user account..." << endl;
    string username, password, roleStr;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    cout << "Enter role \n1. Admin\n2. Passenger\n3. Booking Agent \nChoice: ";
    int roleChoice;
    cin >> roleChoice;
    switch (roleChoice) {
        case 1:
            roleStr = "Admin";
            break;
        case 2:
            roleStr = "Passenger";
            break;
        case 3:
            roleStr = "Booking Agent";
            break;
        default:
            cout << "Invalid choice. Defaulting to Passenger." << endl;
            roleStr = "Passenger";
            break;
    }

    User newUser(username, password, userManager.roleFromString(roleStr));
    while (!userManager.addUserAccount(newUser)) {
        cout << "Invalid username. Please try again." << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        newUser = User(username, password, userManager.roleFromString(roleStr));
    }
    //cout << "User account created successfully." << endl;
}
void Administrator::updateUserAccount(UserManager& userManager) {
    cout << "Updating user account..." << endl;
    std::string username;
    cout<<"Enter username of the account to update: ";
    cin>>username;
    userManager.updateUserAccount(username);
}
void Administrator::deleteUserAccount(UserManager& userManager) {
    cout << "Deleting user account..." << endl;
    std::string username;
    cout<<"Enter username of the account to delete: ";
    cin>>username;
    userManager.deleteUserAccount(username);
}

void Administrator::createFlight(FlightManager& flightManager) {
    flightManager.addFlight();
}
void Administrator::updateFlightDetails(FlightManager& flightManager) {
    string flightNumber;
    flightManager.viewAllFlights();
    cout<<"Enter flight number to update details: ";
    cin>>flightNumber;
    flightManager.updateFlightDetails(flightNumber);
}
void Administrator::updateFlightCrew(FlightManager& flightManager) {
    string flightNumber;
    flightManager.viewAllFlights();
    cout<<"Enter flight number to update crew: ";
    cin>>flightNumber;
    flightManager.updateFlightCrew(flightNumber);
}
void Administrator::updateFlightStatus(FlightManager& flightManager) {
    string flightNumber;
    flightManager.viewAllFlights();
    cout<<"Enter flight number to update status: ";
    cin>>flightNumber;
    flightManager.updateFlightStatus(flightNumber);
}
void Administrator::deleteFlight(FlightManager& flightManager) {
    flightManager.removeFlight();
}   

void Administrator::viewAllFlights(FlightManager& flightManager) {
    flightManager.viewAllFlights();
}
