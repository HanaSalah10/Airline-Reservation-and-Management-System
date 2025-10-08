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
    cout << "Creating flight..." << endl;
    string flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraftType;
    int numberOfSeats;
    string statusStr;
    cout << "Enter flight number: ";
    cin >> flightNumber;
    cout << "Enter origin: ";
    cin >> origin;
    cout << "Enter destination: ";
    cin >> destination;
    cout << "Enter departure date and time (YYYY-MM-DD HH:MM): ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, departureDateTime);
    cout << "Enter arrival date and time (YYYY-MM-DD HH:MM): ";
    getline(cin, arrivalDateTime);
    cout << "Enter aircraft type: ";
    getline(cin, aircraftType);
    cout << "Enter number of seats: ";
    cin >> numberOfSeats;
    cout << "Enter flight status (SCHEDULED, DELAYED, CANCELLED, COMPLETED): ";
    cin >> statusStr;

    FlightStatus status;
    if (statusStr == "SCHEDULED") status = SCHEDULED;
    else if (statusStr == "DELAYED") status = DELAYED;
    else if (statusStr == "CANCELLED") status = CANCELLED;
    else if (statusStr == "COMPLETED") status = COMPLETED;
    else {
        cout << "Invalid flight status. Defaulting to SCHEDULED." << endl;
        status = SCHEDULED;
    }

   // Aircraft aircraft(aircraftType, numberOfSeats);
    //Flight newFlight(flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraft, status);
   // flightManager.addFlight(newFlight);
   // cout << "Flight created successfully." << endl;
}
void Administrator::updateFlight(FlightManager& flightManager) {
    cout << "Updating flight..." << endl;
    string flightNumber;
    cout << "Enter flight number to update: ";
    cin >> flightNumber;

    cout<<"Update:\n1. Origin\n2. Destination\n3. Departure DateTime\n4. Arrival DateTime\n5. Aircraft Type\n6. Number of Seats\n7. Status\nChoice: ";
    int choice;
    cin >> choice;
    string origin, destination, departureDateTime, arrivalDateTime, aircraftType, statusStr;
    int numberOfSeats;
    switch (choice) {
        case 1:
            cout << "Enter new origin: ";
            cin >> origin;
            break;
        case 2:
            cout << "Enter new destination: ";
            cin >> destination;
            break;
        case 3:
            cout << "Enter new departure date and time (YYYY-MM-DD HH:MM): ";
            cin.ignore(); // To ignore the newline character left in the buffer
            getline(cin, departureDateTime);
            break;
        case 4:
            cout << "Enter new arrival date and time (YYYY-MM-DD HH:MM): ";
            cin.ignore(); // To ignore the newline character left in the buffer
            getline(cin, arrivalDateTime);
            break;
        case 5:
            cout << "Enter new aircraft type: ";
            cin.ignore(); // To ignore the newline character left in the buffer
            getline(cin, aircraftType);
            break;
        case 6:
            cout << "Enter new number of seats: ";
            cin >> numberOfSeats;
            break;
        case 7:
            cout << "Enter new flight status (SCHEDULED, DELAYED, CANCELLED, COMPLETED): ";
            cin >> statusStr;
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }   
    FlightStatus status;
    if (statusStr == "SCHEDULED") status = SCHEDULED;
    else if (statusStr == "DELAYED") status = DELAYED;
    else if (statusStr == "CANCELLED") status = CANCELLED;
    else if (statusStr == "COMPLETED") status = COMPLETED;
    else {
        cout << "Invalid flight status. Defaulting to SCHEDULED." << endl;
        status = SCHEDULED;
    }
    //Aircraft aircraft(aircraftType, numberOfSeats);
    //Flight updatedFlight(flightNumber, origin, destination, departureDateTime, arrivalDateTime
   //, aircraft, status);
    //flightManager.updateFlight(flightNumber, updatedFlight);
    //cout << "Flight updated successfully." << endl;
}
void Administrator::deleteFlight(FlightManager& flightManager) {
    cout << "Deleting flight..." << endl;
    string flightNumber;
    cout << "Enter flight number to delete: ";
    cin >> flightNumber;
    flightManager.removeFlight(flightNumber);
    cout << "Flight deleted successfully." << endl;
}   
