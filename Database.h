#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <algorithm>
#include "JobSeeker.h"
#include "Employer.h"
#include "Job.h"
#include "JobApplication.h"

class Database {
    vector<JobSeeker> jobSeekers;
    vector<Employer> employers;
    vector<Job> jobs;
    vector<JobApplication> applications;

public:
    // Default constructor
    Database() {}

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
        for (int i = 0; i < jobSeekers.size(); i++) {
            if (jobSeekers[i].getUsername() == username) {
                return &jobSeekers[i];
            }
        }
        return nullptr;
    }

    Employer* findEmployer(const string& username) {
        for (int i = 0; i < employers.size(); i++) {
            if (employers[i].getUsername() == username) {
                return &employers[i];
            }
        }
        return nullptr;
    }

    Job* findJob(int jobId) {
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i].getJobId() == jobId) {
                return &jobs[i];
            }
        }
        return nullptr;
    }

    vector<Job> getAllJobs() const {
        return jobs;
    }

    vector<JobApplication> getApplicationsForJob(int jobId) {
        vector<JobApplication> result;
        for ( auto& app : applications) {
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

    // Update application status
    bool updateApplicationStatus(int applicationId, ApplicationStatus newStatus) {
        for (auto& app : applications) {
            if (app.getApplicationId() == applicationId) {
                app.setStatus(newStatus);
                return true;
            }
        }
        return false;
    }
};

#endif // DATABASE_H
