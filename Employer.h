#ifndef EMPLOYER_H
#define EMPLOYER_H

#include "User.h"
#include "Job.h"
#include <vector>
#include <iostream>

class Employer : public User {
    string companyName;
    string industry;
    string companyDescription;
    vector<int> postedJobs;

public:
    Employer(string username, string password, string email, string contactInfo,
             string companyName, string industry, string companyDescription = "")
        : User(username, password, email, contactInfo),
          companyName(companyName), industry(industry), companyDescription(companyDescription) {}

    string getCompanyName() const { return companyName; }
    void setCompanyName(string name) { companyName = name; }

    string getIndustry() const { return industry; }
    void setIndustry(string ind) { industry = ind; }

    string getCompanyDescription() const { return companyDescription; }
    void setCompanyDescription(string desc) { companyDescription = desc; }

    void postJob(const Job& job) { postedJobs.push_back(job.getJobId()); }

    vector<int> getPostedJobs() const { return postedJobs; }

    // Override the pure virtual function
    void displayProfile() const override {
        cout << "Employer Profile:" << endl;
        cout << "Company: " << companyName << endl;
        cout << "Industry: " << industry << endl;
        cout << "Email: " << email << endl;
        cout << "Contact: " << contactInfo << endl;
        cout << "Description: " << companyDescription << endl;
        cout << "Number of posted jobs: " << postedJobs.size() << endl;
    }
};

#endif // EMPLOYER_H
