#include <string>

#ifndef CREW_HPP
#define CREW_HPP


class Crew {
protected:
    std::string id;
    std::string name;
    std::string contactInfo;
    bool isAvailable;
    
public:
    Crew(const std::string& id, const std::string& name, const std::string& contact);
    
    virtual ~Crew();
    
    // Getters and setters
    std::string getId() const;
    std::string getName() const;
    bool getAvailability() const;
    void setAvailability(bool available);
    
    virtual void displayInfo() const = 0;  // Pure virtual function
};
#endif // CREW_HPP