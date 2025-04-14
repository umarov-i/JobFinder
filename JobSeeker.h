#ifndef JOBSEEKER_H
#define JOBSEEKER_H

#include "User.h"
#include <vector>
#include <iostream>

class JobSeeker : public User {
    string resume;
    vector<string> skills;
    vector<string> experience;
    vector<int> appliedJobs;

public:
    JobSeeker(string username, string password, string email, string contactInfo)
        : User(username, password, email, contactInfo) {}

    void uploadResume(string resumePath) { resume = resumePath; }

    void addSkill(string skill) { skills.push_back(skill); }

    void addExperience(string exp) { experience.push_back(exp); }

    vector<string> getSkills() const { return skills; }

    vector<string> getExperience() const { return experience; }

    string getResume() const { return resume; }

    void applyForJob(int jobId) { appliedJobs.push_back(jobId); }

    vector<int> getAppliedJobs() const { return appliedJobs; }

    // Override the pure virtual function
    void displayProfile() const override {
        cout << "Job Seeker Profile:" << endl;
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
        cout << "Contact: " << contactInfo << endl;

        cout << "Skills: ";
        for (const auto& skill : skills) {
            cout << skill << ", ";
        }
        cout << endl;

        cout << "Experience: " << endl;
        for (const auto& exp : experience) {
            cout << "- " << exp << endl;
        }
    }
};

#endif // JOBSEEKER_H
