#ifndef USER_HPP
#define USER_HPP
#include <string>
using namespace std;
enum class Role { ADMIN, PASSENGER, BOOKING_AGENT };
class User
{
    protected:
    string username;
    Role role;

    private:
        string password;

    public:
        User(const string& username, const string& password, Role role)
            : username(username), role(role), password(password) {}
        virtual ~User() = default;  // Add virtual destructor
        virtual string getUsername() const { return username; }
        virtual string getPassword() const { return password; }
        virtual Role getRole() const { return role; }
        virtual void setPassword(const string& newPassword) { password = newPassword; }
        virtual void setRole(Role newRole) { role = newRole; }
        virtual void setUsername(const string& newUsername) { username = newUsername; }
};
#endif // USER_HPP