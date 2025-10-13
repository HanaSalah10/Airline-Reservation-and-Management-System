#include "include/AuthenticationManager.hpp"
#include "include/UserManager.hpp"
#include "include/Administrator.hpp"
#include "include/Menu.hpp"
#include "include/AircraftManager.hpp"
#include "include/FlightManager.hpp"
#include "include/CrewManager.hpp"
int main()
{
    UserManager userManager;
    AuthenticationManager authManager(userManager);
    AircraftManager aircraftManager;
    CrewManager crewManager;
    FlightManager flightManager(aircraftManager,crewManager);
    bool loggedIn = false;

    Role role = authManager.selectRole();
    User* currentUser = authManager.login(role);
   if(currentUser  && currentUser->getRole() == Role::ADMIN) {
       loggedIn = true;
       Administrator admin; // Create Administrator object
       while(loggedIn) {
           admin.adminMainMenu();
           int choice;
           std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch(choice) {
                case 1:
                    admin.manageFlightsMenu();
                    // Further implementation for managing flights
                    int flightChoice;
                    std::cout << "Enter your choice: ";
                    std::cin >> flightChoice;
                    switch(flightChoice) {
                        case 1:
                            admin.createFlight(flightManager);
                            break;
                        case 2:
                             admin.updateFlightMenu();
                             int updateChoice;
                             std::cout << "Enter your choice: ";
                             std::cin >> updateChoice;
                             switch(updateChoice) {
                                case 1:
                                    admin.updateFlightDetails(flightManager);
                                    break;
                                case 2:
                                    admin.updateFlightCrew(flightManager);
                                    break;
                                case 3:
                                    admin.updateFlightStatus(flightManager);
                                    break;
                                case 4:
                                    // Back to Flights Menu
                                    break;
                             }
                        break;
                    
                        case 3:
                            admin.deleteFlight(flightManager);
                            break;
                        case 4:
                            admin.viewAllFlights(flightManager);
                            break;
                        case 5:
                            // Back to main menu
                            break;
                       }
                    break;
                case 2:
                    admin.manageAircraftMenu();
                    // Further implementation for managing aircraft
                    break;
                case 3:
                    admin.manageUsersMenu();
                    int userChoice;
                    std::cout << "Enter your choice: ";
                    std::cin >> userChoice;
                    switch(userChoice) {
                        case 1:
                            admin.createUserAccount(userManager);
                            break;
                        case 2:
                            admin.updateUserAccount(userManager);
                            break;
                        case 3:
                            admin.deleteUserAccount(userManager);
                            break;
                        case 4:
                            // Back to main menu
                            break;
                    }
                    break;
                case 4:
                    // Generate reports
                    break;
                case 5:
                    authManager.logout();
                    loggedIn = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
    }

    return 0;
}