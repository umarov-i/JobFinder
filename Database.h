#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <algorithm>
#include "JobSeeker.h"
#include "Employer.h"
#include "Job.h"
#include "JobApplication.h"

// Singleton pattern for Database
class Database {
    vector<JobSeeker> jobSeekers;
    vector<Employer> employers;
    vector<Job> jobs;
    vector<JobApplication> applications;

    static Database* instance;

    // Private constructor for singleton
    Database() {}

    // Prevent copying
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

public:
    // Get singleton instance
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database();
        }
        return instance;
    }

    void addJobSeeker(const JobSeeker& jobSeeker) {
        jobSeekers.push_back(jobSeeker);
    }

    void addEmployer(const Employer& employer) {
        employers.push_back(employer);
    }

    void addJob(const Job& job) {
        jobs.push_back(job);
    }

    void addApplication(const JobApplication& application) {
        applications.push_back(application);
    }

    JobSeeker* findJobSeeker(const string& username) {
        auto it = find_if(jobSeekers.begin(), jobSeekers.end(),
                              [&username](const JobSeeker& js) { return js.getUsername() == username; });

        if (it != jobSeekers.end()) {
            return &(*it);
        }
        return nullptr;
    }

    Employer* findEmployer(const string& username) {
        auto it = find_if(employers.begin(), employers.end(),
                              [&username](const Employer& emp) { return emp.getUsername() == username; });

        if (it != employers.end()) {
            return &(*it);
        }
        return nullptr;
    }

    Job* findJob(int jobId) {
        auto it = find_if(jobs.begin(), jobs.end(),
                              [jobId](const Job& job) { return job.getJobId() == jobId; });

        if (it != jobs.end()) {
            return &(*it);
        }
        return nullptr;
    }

    vector<Job> getAllJobs() const {
        return jobs;
    }

    vector<JobApplication> getApplicationsForJob(int jobId) {
        vector<JobApplication> result;
        for (const auto& app : applications) {
            if (app.getJobId() == jobId) {
                result.push_back(app);
            }
        }
        return result;
    }

    vector<JobApplication> getApplicationsByJobSeeker(const string& username) {
        vector<JobApplication> result;
        for (const auto& app : applications) {
            if (app.getJobSeekerUsername() == username) {
                result.push_back(app);
            }
        }
        return result;
    }

    ~Database() {
        // Clean up singleton instance
        delete instance;
    }
};

// Initialize static member
Database* Database::instance = nullptr;

#endif // DATABASE_H
