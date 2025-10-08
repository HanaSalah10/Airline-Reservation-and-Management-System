#include "../include/AuthenticationManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
AuthenticationManager::AuthenticationManager(UserManager& userManager) : userManager(userManager) {}

Role AuthenticationManager::selectRole() {
    int choice;
    std::cout << "Select Role:\n1. Admin\n2. Passenger\n3. Booking Agent\nChoice: ";
    std::cin >> choice;
    switch (choice) {
        case 1: return Role::ADMIN;
        case 2: return Role::PASSENGER;
        case 3: return Role::BOOKING_AGENT;
        default:
            std::cout << "Invalid choice. Defaulting to Passenger." << std::endl;
            return Role::PASSENGER;
    }
}
User* AuthenticationManager::login(Role role) {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    auto& users = userManager.getAllUsers();

    for (auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password && user.getRole() == role) {
            std::cout << "Login successful!" << std::endl;
            return &user;
        }
    }
    std::cout << "Invalid credentials or role." << std::endl;
    return nullptr;
}

void AuthenticationManager::logout() {
    cout << "Logged out successfully." << endl;
}

