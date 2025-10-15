#include "../include/UserManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
UserManager::UserManager(const std::string& filename) {
    loadUsers(filename);
    for (const auto& user : users) {
        usernames.insert(user.getUsername());
    }
}
Role UserManager::roleFromString(const std::string& roleStr) {
    if (roleStr == "Admin" || roleStr == "ADMIN" || roleStr == "admin") return Role::ADMIN;
    if (roleStr == "Passenger" || roleStr == "PASSENGER" || roleStr == "passenger") return Role::PASSENGER;
    if (roleStr == "Booking Agent" || roleStr == "BOOKING_AGENT" || roleStr == "booking agent") return Role::BOOKING_AGENT;
    throw invalid_argument("Invalid role string");
}

void UserManager::loadUsers(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string username, password, roleStr;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, roleStr);
        
        try {
            Role role = roleFromString(roleStr);
            users.push_back(User(username, password, role));
        } catch (const invalid_argument& e) {
            cerr << "Invalid role in file: " << roleStr << endl;
        }
    }
    file.close();
    
}
void UserManager::saveUsers(const std::string& filename) {
     ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& user : users) {
        string roleStr;
        switch (user.getRole()) {
            case Role::ADMIN: roleStr = "admin"; break;
            case Role::PASSENGER: roleStr = "passenger"; break;
            case Role::BOOKING_AGENT: roleStr = "booking agent"; break;
        }
        file << user.getUsername() << "," << user.getPassword() << "," << roleStr << endl;
    }
    file.close();
    cout << "User data saved successfully." << endl;
}
bool UserManager::addUserAccount(const User& user) {
    if (usernames.find(user.getUsername()) != usernames.end()) {
        cout << "Username already exists. Choose a different username." << endl;
        return false;
    }
    users.push_back(user);
    usernames.insert(user.getUsername());
    cout << "User added successfully." << endl;
    saveUsers(); // Save changes immediately

    return true;
}
void UserManager::updateUserAccount(const std::string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username) {
            cout << "Update:\n1.Password 2.Role\nChoice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    string newPassword;
                    cout << "Enter new password for " << username << ": ";
                    cin >> newPassword;
                    user.setPassword(newPassword);
                    saveUsers(); // Save changes immediately
                    cout << "Password updated successfully." << endl;
                    break;
                }
                case 2: {
                    cout << "Select new role:\n1. Admin\n2. Passenger\n3. Booking Agent\nChoice: ";
                    int roleChoice;
                    cin >> roleChoice;
                    Role newRole = (roleChoice == 1) ? Role::ADMIN :
                                   (roleChoice == 2) ? Role::PASSENGER :
                                   Role::BOOKING_AGENT;
                    user.setRole(newRole);
                    saveUsers(); // Save changes immediately
                    cout << "Role updated successfully." << endl;
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
            }
            return;
        }
    }
    cout << "User not found." << endl;
}
void UserManager::deleteUserAccount(const std::string& username) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getUsername() == username) {
            users.erase(it);
            usernames.erase(username);
            saveUsers(); // Save changes immediately
            cout << "User account deleted successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}
User* UserManager::getUser(const std::string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username) {
            return &user;
        }
    }
    return nullptr; // User not found
}