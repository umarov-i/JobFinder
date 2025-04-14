#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User {
protected:
    string username;
    string password;
    string email;
    string contactInfo;

public:
    User(string username, string password, string email, string contactInfo)
        : username(username), password(password), email(email), contactInfo(contactInfo) {}

    string getUsername() const { return username; }
    void setUsername(string username) { this->username = username; }

    string getEmail() const { return email; }
    void setEmail(string email) { this->email = email; }

    string getContactInfo() const { return contactInfo; }
    void setContactInfo(string contactInfo) { this->contactInfo = contactInfo; }

    // Pure virtual function (abstract method)
    virtual void displayProfile() const = 0;

    // Virtual function
    virtual bool authenticate(string inputUsername, string inputPassword) const {
        return (inputUsername == username && inputPassword == password);
    }

    // Virtual destructor
    virtual ~User() {}
};

#endif // USER_H
