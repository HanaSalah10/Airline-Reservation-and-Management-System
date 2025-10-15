#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP
#include <iostream>
#include <vector>
#include <unordered_set>
#include "User.hpp"

class UserManager {
    std::vector<User> users;
    std::unordered_set<std::string> usernames; // To ensure unique usernames

public: 
    UserManager(const std::string& filename = "database/users.txt"); // Constructor that loads existing users
    void loadUsers(const std::string& filename = "database/users.txt");
    void saveUsers(const std::string& filename = "database/users.txt");

    Role roleFromString(const std::string& roleStr);
    //std::string roleToString(Role role);
    bool addUserAccount(const User& user);
    void updateUserAccount(const std::string& username);
    void deleteUserAccount(const std::string& username);

    std::vector<User>& getAllUsers() { return users; }
    User* getUser(const std::string& username);
    ~UserManager() {}
};
#endif // USERMANAGER_HPP