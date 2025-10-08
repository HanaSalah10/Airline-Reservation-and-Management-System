#include "include/AuthenticationManager.hpp"
#include "include/UserManager.hpp"
#include "include/Administrator.hpp"
#include "include/Menu.hpp"
int main()
{
    UserManager userManager;
    AuthenticationManager authManager(userManager);
    bool loggedIn = false;

    Role role = authManager.selectRole();
    User* currentUser = authManager.login(role);
   
    if(currentUser  && currentUser->getRole() == Role::ADMIN) {
        loggedIn = true;
        Administrator* admin = dynamic_cast<Administrator*>(currentUser);
        while(loggedIn) {
            admin->adminMainMenu();
            int choice;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch(choice) {
                case 1:
                    admin->manageFlightsMenu();
                    // Further implementation for managing flights
                    break;
                case 2:
                    admin->manageAircraftMenu();
                    // Further implementation for managing aircraft
                    break;
                case 3:
                    admin->manageUsersMenu();
                    int userChoice;
                    std::cout << "Enter your choice: ";
                    std::cin >> userChoice;
                    switch(userChoice) {
                        case 1:
                            admin->createUserAccount(userManager);
                            break;
                        case 2:
                            admin->updateUserAccount(userManager);
                            break;
                        case 3:
                            admin->deleteUserAccount(userManager);
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