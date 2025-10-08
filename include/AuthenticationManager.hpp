#ifndef AUTHENTICATIONMANAGER_HPP
#define AUTHENTICATIONMANAGER_HPP

#include "../include/UserManager.hpp"
#include <vector>
#include <unordered_set>

class AuthenticationManager {
    private:
       UserManager& userManager;
    public:
        AuthenticationManager(UserManager& userManager);
        Role selectRole();

        // Authentication
        User* login(Role role);
        void logout();
        

};
#endif // AUTHENTICATIONMANAGER_HPP