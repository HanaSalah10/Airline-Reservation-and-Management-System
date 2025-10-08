#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include "../include/FlightManager.hpp"
#include "../include/AuthenticationManager.hpp"
#include "../include/UserManager.hpp"
#include "../include/User.hpp"
class Administrator : public User
{
    public:

    //utlity functions
    void adminMainMenu()
    {
        cout << "1. Manage Flights" << endl;
        cout << "2. Manage Aircraft" << endl;
        cout << "3. Manage Users" << endl;
        cout << "4. Generate Reports" << endl;
        cout << "5. Logout" << endl;
    }

    void manageFlightsMenu()
    {
        cout << "1. Add New Flight" << endl;
        cout << "2. Update Existing Flight" << endl;
        cout << "3. Remove Flight" << endl;
        cout << "4. View All Flights" << endl;
        cout << "5. Back to Main Menu" << endl;
    }

    void manageUsersMenu()
    {
        cout << "1. Create User Account" << endl;
        cout << "2. Update User Account" << endl;
        cout << "3. Delete User Account" << endl;
        cout << "4. Back to Main Menu" << endl;
    }
    void manageAircraftMenu()
    {
        cout << "1. Add New Aircraft" << endl;
        cout << "2. Update Existing Aircraft" << endl;
        cout << "3. Remove Aircraft" << endl;
        cout << "4. View All Aircraft" << endl;
        cout << "5. Back to Main Menu" << endl;
    }


    // User management
    void createUserAccount(UserManager& userManager);
    void updateUserAccount(UserManager& userManager);
    void deleteUserAccount(UserManager& userManager);
   // Flight management
    void createFlight(FlightManager& flightManager);
    void updateFlight(FlightManager& flightManager);
    void deleteFlight(FlightManager& flightManager);

};
#endif // ADMINISTRATOR_HPP