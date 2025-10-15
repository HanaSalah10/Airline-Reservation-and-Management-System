#include "../include/FlightManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


FlightManager::FlightManager(AircraftManager& aircraftManager, CrewManager& crewManager, const std::string& filename) 
    : aircraftManager(aircraftManager), crewManager(crewManager) {
    loadFlightData(filename);
}
void FlightManager::loadFlightData(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraftID  , statusStr;
        int numberOfSeats;
        getline(ss, flightNumber, ',');
        getline(ss, origin, ',');
        getline(ss, destination, ',');
        getline(ss, departureDateTime, ',');
        getline(ss, arrivalDateTime, ',');
        getline(ss , aircraftID , ',');
        getline(ss, statusStr); // Read until end of line
        Aircraft* aircraft = aircraftManager.getAircraftById(aircraftID);
        
        if (!aircraft) {
            cerr << "Aircraft with ID " << aircraftID << " not found. Skipping flight " << flightNumber << endl;
            continue; // Skip this flight entry
        }
        
        aircraft->setAvailability(false); // Mark aircraft as unavailable
        
        FlightStatus status;
        if (statusStr == "SCHEDULED") status = SCHEDULED;
        else if (statusStr == "DELAYED") status = DELAYED;
        else if (statusStr == "CANCELLED") status = CANCELLED;
        else if (statusStr == "COMPLETED") status = COMPLETED;
        else {
            cerr << "Invalid flight status in file: " << statusStr << endl;
            continue; // Skip invalid entries
        } 
        flights.push_back(Flight(flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraft, status));
        flightNumbers.insert(flightNumber);
    }
    file.close();
}
void FlightManager::saveFlightData(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& flight : flights) {
        file << flight.getFlightNumber() << ","
                << flight.getOrigin() << ","
                << flight.getDestination() << ","
                << flight.getDepartureDateTime() << ","
                << flight.getArrivalDateTime() << ","
                << flight.getAircraft()->getID() << ",";
        switch (flight.getStatus()) {
            case SCHEDULED: file << "SCHEDULED"; break;
            case DELAYED: file << "DELAYED"; break;
            case CANCELLED: file << "CANCELLED"; break;
            case COMPLETED: file << "COMPLETED"; break;
        }
        file << endl;
    }
    file.close();
}
void FlightManager::addFlight() {
    std::cout << "Creating flight..." << std::endl;
    string flightNumber, origin, destination, departureDateTime, arrivalDateTime, statusStr;
    std::cout << "Enter flight number: ";
    std::cin >> flightNumber;
    std::cout << "Enter origin: ";
    std::cin.ignore(); // Clear any leftover newline characters
    std::getline(std::cin, origin);  // This reads the entire line including spaces
    std::cout << "Enter destination: ";
    std::cin.ignore(); // Clear any leftover newline characters
    std::getline(std::cin, destination);  // This reads the entire line including spaces

    std::cout << "Enter departure date and time (YYYY-MM-DD HH:MM): ";
    std::cin.ignore(); // To ignore the newline character left in the buffer
    std::getline(std::cin, departureDateTime);
    std::cout << "Enter arrival date and time (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin, arrivalDateTime);

    // List available aircrafts
    vector<Aircraft>& allAircrafts = aircraftManager.getAllAircrafts();
    std::cout << "Available Aircrafts: " << std::endl;
    for (const auto& ac : allAircrafts) {
        if (ac.getIsAvailable()) {
            std::cout << "ID: " << ac.getID() << ", Type: " << ac.getType() 
                        << ", Rows: " << ac.getNumberOfRows() 
                        << ", Seats/Row: " << ac.getSeatsPerRow() << std::endl;
        }
    }
    string aircraftID;
    std::cout << "Enter aircraft ID from the available list: ";
    std::cin >> aircraftID;
    Aircraft* aircraft = aircraftManager.getAircraftById(aircraftID);
    if (!aircraft || !aircraft->getIsAvailable()) {
        std::cout << "Invalid or unavailable aircraft ID." << std::endl;
        return;
    }
    aircraft->setAvailability(false); // Mark aircraft as unavailable

    std::cout << "Enter flight status (SCHEDULED, DELAYED, CANCELLED, COMPLETED): ";
    std::cin >> statusStr;

    FlightStatus status;
    if (statusStr == "SCHEDULED") status = SCHEDULED;
    else if (statusStr == "DELAYED") status = DELAYED;
    else if (statusStr == "CANCELLED") status = CANCELLED;
    else if (statusStr == "COMPLETED") status = COMPLETED;
    else {
        std::cout << "Invalid flight status. Defaulting to SCHEDULED." << std::endl;
        status = SCHEDULED;
    }
    Flight newFlight(flightNumber, origin, destination, departureDateTime, arrivalDateTime, aircraft, status);
    flights.push_back(newFlight);
    flightNumbers.insert(flightNumber);
    
    // Ask if user wants to assign crew now
    char assignCrewNow;
    std::cout << "Do you want to assign crew to this flight now? (y/n): ";
    std::cin >> assignCrewNow;

    if (assignCrewNow == 'y' || assignCrewNow == 'Y') {
        // Get the reference to the flight we just added
        Flight& addedFlight = flights.back();
        assignCrewToFlight(addedFlight);
    } else {
        std::cout << "Flight created without crew assignment. You can assign crew later." << std::endl;
    }
    
    saveFlightData(); // Save changes immediately
    std::cout << "Flight created successfully." << std::endl;
}
void FlightManager::removeFlight() {
    string flightNumber;
    viewAllFlights();
    std::cout << "Enter flight number to remove: ";
    std::cin >> flightNumber;
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            flights.erase(it);
            flightNumbers.erase(flightNumber);
            saveFlightData(); // Save changes immediately
            std::cout << "Flight removed successfully." << std::endl;
            return;
        }
    }
    std::cout << "Flight not found." << std::endl;
}
void FlightManager::viewAllFlights() {
    if (flights.empty()) {
        std::cout << "No flights available." << std::endl;
        return;
    }
    for (const auto& flight : flights) {
        flight.displayFlightInfo();
        std::cout << "------------------------" << std::endl;
    }
}
void FlightManager::assignCrewToFlight(Flight& flight) {
    std::cout << "\n=== CREW ASSIGNMENT FOR FLIGHT " << flight.getFlightNumber() << " ===" << std::endl;

    // Assign Pilot
    std::cout << "\nAvailable Pilots:" << std::endl;
    std::vector<Pilot>& allPilots = crewManager.getPilots();
    for (size_t i = 0; i < allPilots.size(); ++i) {
        if (allPilots[i].getAvailability()) {
            std::cout << i + 1 << ". " << allPilots[i].getName() 
                      << " (" << allPilots[i].getId() << ") - " 
                      << allPilots[i].getFlightHours() << " hours" << std::endl;
        }
    }
    
    int pilotChoice;
    std::cout << "Select pilot (enter number): ";
    std::cin >> pilotChoice;

    if (pilotChoice > 0 && pilotChoice <= allPilots.size() && 
        allPilots[pilotChoice - 1].getAvailability()) {
        flight.assignPilot(&allPilots[pilotChoice - 1]);
        allPilots[pilotChoice - 1].setAvailability(false);
        std::cout << "Pilot " << allPilots[pilotChoice - 1].getName() << " assigned successfully!" << std::endl;
    } else {
        std::cout << "Invalid selection or pilot unavailable!" << std::endl;
    }
    
    // Assign Flight Attendants
    std::cout << "\nAvailable Flight Attendants:" << std::endl;
    std::vector<FlightAttendant>& allAttendants = crewManager.getFlightAttendants();
    for (size_t i = 0; i < allAttendants.size(); ++i) {
        if (allAttendants[i].getAvailability()) {
            std::cout << i + 1 << ". " << allAttendants[i].getName() 
                      << " (" << allAttendants[i].getId() << ") - " 
                      << allAttendants[i].getCertificationLevel() << std::endl;
        }
    }
    
    int numAttendants;
    Aircraft* aircraft = flight.getAircraft();
    // int recommendedAttendants = (aircraft->getNumberOfSeats() <= 100) ? 2 : 
    //                            (aircraft->getNumberOfSeats() <= 200) ? 3 : 4;
    
    // std::cout << "Recommended flight attendants for " << aircraft->getNumberOfSeats() 
    //      << " seat aircraft: " << recommendedAttendants << std::endl;
    std::cout << "How many flight attendants to assign? ";
    std::cin >> numAttendants;
    
    for (int i = 0; i < numAttendants; ++i) {
        int attendantChoice;
        std::cout << "Select flight attendant " << (i + 1) << " (enter number): ";
        std::cin >> attendantChoice;

        if (attendantChoice > 0 && attendantChoice <= allAttendants.size() && 
            allAttendants[attendantChoice - 1].getAvailability()) {
            flight.assignFlightAttendant(&allAttendants[attendantChoice - 1]);
            allAttendants[attendantChoice - 1].setAvailability(false);
            std::cout << "Flight Attendant " << allAttendants[attendantChoice - 1].getName() 
                 << " assigned successfully!" << std::endl;
        } else {
            std::cout << "Invalid selection or attendant unavailable!" << std::endl;
            i--; // Retry this assignment
        }
    }

    std::cout << "Crew assignment completed!" << std::endl;
}

void FlightManager::assignPilot() {
    std::cout << "Enter flight number to assign pilot: ";
    std::string flightNumber;
    std::cin >> flightNumber;

    Flight* flight = searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    }

    std::cout << "Available Pilots:" << std::endl;
    std::vector<Pilot>& allPilots = crewManager.getPilots();
    for (size_t i = 0; i < allPilots.size(); ++i) {
        if (allPilots[i].getAvailability()) {
            std::cout << i + 1 << ". " << allPilots[i].getName() 
                      << " (" << allPilots[i].getId() << ")" << std::endl;
        }
    }
    
    int choice;
    std::cout << "Select pilot (enter number): ";
    std::cin >> choice;

    if (choice > 0 && choice <= allPilots.size() && 
        allPilots[choice - 1].getAvailability()) {
        flight->assignPilot(&allPilots[choice - 1]);
        allPilots[choice - 1].setAvailability(false);
        std::cout << "Pilot assigned successfully!" << std::endl;
    } else {
        std::cout << "Invalid selection!" << std::endl;
    }
}

void FlightManager::assignFlightAttendants() {
    std::cout << "Enter flight number to assign flight attendants: ";
    std::string flightNumber;
    std::cin >> flightNumber;

    Flight* flight = searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    }

    std::cout << "Available Flight Attendants:" << std::endl;
    std::vector<FlightAttendant>& allAttendants = crewManager.getFlightAttendants();
    for (size_t i = 0; i < allAttendants.size(); ++i) {
        if (allAttendants[i].getAvailability()) {
            std::cout << i + 1 << ". " << allAttendants[i].getName() 
                      << " (" << allAttendants[i].getId() << ")" << std::endl;
        }
    }
    
    int numAttendants;
    std::cout << "How many flight attendants to assign? ";
    std::cin >> numAttendants;

    for (int i = 0; i < numAttendants; ++i) {
        int choice;
        std::cout << "Select flight attendant " << (i + 1) << " (enter number): ";
        std::cin >> choice;

        if (choice > 0 && choice <= allAttendants.size() && 
            allAttendants[choice - 1].getAvailability()) {
            flight->assignFlightAttendant(&allAttendants[choice - 1]);
            allAttendants[choice - 1].setAvailability(false);
            std::cout << "Flight attendant assigned successfully!" << std::endl;
        } else {
            std::cout << "Invalid selection!" << std::endl;
            i--; // Retry this assignment
        }
    }
}

Flight* FlightManager::searchFlight(const std::string& flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            return &flight;
        }
    }
    return nullptr;
}
void FlightManager::updateFlightDetails(const std::string& flightNumber) {
    Flight* flight = searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    }

    std::cout << "Updating details for flight " << flightNumber << std::endl;
    std::string origin, destination, departureDateTime, arrivalDateTime, statusStr;

    std::cout << "Enter new origin (current: " << flight->getOrigin() << "): ";
    std::cin.ignore(); // Clear any leftover newline characters
    std::getline(std::cin, origin);
    if (!origin.empty()) {
        flight->setOrigin(origin);
    }

    std::cout << "Enter new destination (current: " << flight->getDestination() << "): ";
    std::getline(std::cin, destination);
    if (!destination.empty()) {
        flight->setDestination(destination);
    }

    std::cout << "Enter new departure date and time (current: " << flight->getDepartureDateTime() << ") (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin, departureDateTime);
    if (!departureDateTime.empty()) {
        flight->setDepartureDateTime(departureDateTime);
    }

    std::cout << "Enter new arrival date and time (current: " << flight->getArrivalDateTime() << ") (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin, arrivalDateTime);
    if (!arrivalDateTime.empty()) {
        flight->setArrivalDateTime(arrivalDateTime);
    }

    std::cout << "Enter new flight status (current: ";
    switch (flight->getStatus()) {
        case SCHEDULED: std::cout << "SCHEDULED"; break;
        case DELAYED: std::cout << "DELAYED"; break;
        case CANCELLED: std::cout << "CANCELLED"; break;
        case COMPLETED: std::cout << "COMPLETED"; break;
    }
    std::cout << ") (SCHEDULED, DELAYED, CANCELLED, COMPLETED): ";
    std::getline(std::cin, statusStr);

    if (!statusStr.empty()) {
        FlightStatus status;
        if (statusStr == "SCHEDULED") status = SCHEDULED;
        else if (statusStr == "DELAYED") status = DELAYED;
        else if (statusStr == "CANCELLED") status = CANCELLED;
        else if (statusStr == "COMPLETED") status = COMPLETED;
        else {
            std::cout << "Invalid flight status. Keeping current status." << std::endl;
            status = flight->getStatus(); // Keep current status
        }
        flight->setStatus(status);
    }   
    saveFlightData(); // Save changes immediately
    std::cout << "Flight details updated successfully." << std::endl;
}
void FlightManager::updateFlightCrew(const std::string& flightNumber) {
    Flight* flight = searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    }

    std::cout << "Updating crew for flight " << flightNumber << std::endl;
    char choice;
    
    // Update Pilot
    std::cout << "Current Pilot: ";
    Pilot* currentPilot = flight->getAssignedPilot();
    if (currentPilot) {
        std::cout << currentPilot->getName() << " (" << currentPilot->getId() << ")" << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }

    std::cout << "Do you want to change the pilot? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        // Make current pilot available again
        if (currentPilot) {
            currentPilot->setAvailability(true);
        }

        std::cout << "Available Pilots:" << std::endl;
        std::vector<Pilot>& allPilots = crewManager.getPilots();
        for (size_t i = 0; i < allPilots.size(); ++i) {
            if (allPilots[i].getAvailability()) {
                std::cout << i + 1 << ". " << allPilots[i].getName() 
                          << " (" << allPilots[i].getId() << ")" << std::endl;
            }
        }
        
        int pilotChoice;
        std::cout << "Select new pilot (enter number): ";
        std::cin >> pilotChoice;

        if (pilotChoice > 0 && pilotChoice <= allPilots.size() && 
            allPilots[pilotChoice - 1].getAvailability()) {
            flight->assignPilot(&allPilots[pilotChoice - 1]);
            allPilots[pilotChoice - 1].setAvailability(false);
            std::cout << "Pilot assigned successfully!" << std::endl;
        } else {
            std::cout << "Invalid selection or pilot unavailable!" << std::endl;
        }
    }
    // Update Flight Attendants
    std::cout << "\nCurrent Flight Attendants:" << std::endl;
    std::vector<FlightAttendant*> currentAttendants = flight->getAssignedFlightAttendants();
    if (currentAttendants.empty()) {
        std::cout << "None" << std::endl;
    } else {
        for (const auto& attendant : currentAttendants) {
            std::cout << attendant->getName() << " (" << attendant->getId() << ")" << std::endl;
        }       
    }

    std::cout << "Do you want to change/assign flight attendants? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        // Make current attendants available again
        for (const auto& attendant : currentAttendants) {
            attendant->setAvailability(true);
        }
        // Clear current attendants from flight
        currentAttendants.clear();      
        // Now assign new attendants
        std::cout << "Available Flight Attendants:" << std::endl; 
        std::vector<FlightAttendant>& allAttendants = crewManager.getFlightAttendants();
        for (size_t i = 0; i < allAttendants.size(); ++i) {
            if (allAttendants[i].getAvailability()) {
                std::cout << i + 1 << ". " << allAttendants[i].getName() 
                     << " (" << allAttendants[i].getId() << ")" << std::endl;
            }
        }       

        int numAttendants;
        std::cout << "How many flight attendants to assign? ";
        std::cin >> numAttendants;   

        for (int i = 0; i < numAttendants; ++i) {
            int attendantChoice;
            std::cout << "Select flight attendant " << (i + 1) << " (enter number): ";
            std::cin >> attendantChoice;
            
            if (attendantChoice > 0 && attendantChoice <= allAttendants.size() && 
                allAttendants[attendantChoice - 1].getAvailability()) {
                flight->assignFlightAttendant(&allAttendants[attendantChoice - 1]);
                allAttendants[attendantChoice - 1].setAvailability(false);
                std::cout << "Flight attendant assigned successfully!" << std::endl;
            } else {
                std::cout << "Invalid selection or attendant unavailable!" << std::endl;
                i--; // Retry this assignment
            }
        }
    }   
    saveFlightData(); // Save changes immediately
    std::cout << "Flight crew updated successfully." << std::endl;
}

void FlightManager::updateFlightStatus(const std::string& flightNumber) {
    Flight* flight = searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    }

    std::cout << "Current status: ";
    switch (flight->getStatus()) {
        case SCHEDULED: std::cout << "SCHEDULED"; break;
        case DELAYED: std::cout << "DELAYED"; break;
        case CANCELLED: std::cout << "CANCELLED"; break;
        case COMPLETED: std::cout << "COMPLETED"; break;
    }
    std::cout << std::endl;

    std::string statusStr;
    std::cout << "Enter new flight status (SCHEDULED, DELAYED, CANCELLED, COMPLETED): ";
    std::cin >> statusStr;
    
    FlightStatus status;
    if (statusStr == "SCHEDULED") status = SCHEDULED;
    else if (statusStr == "DELAYED") status = DELAYED;
    else if (statusStr == "CANCELLED") status = CANCELLED;
    else if (statusStr == "COMPLETED") status = COMPLETED;
    else {
        std::cout << "Invalid flight status. Keeping current status." << std::endl;
        return; // Exit without changing
    }
    
    flight->setStatus(status);
    saveFlightData(); // Save changes immediately
    std::cout << "Flight status updated successfully." << std::endl;
}
