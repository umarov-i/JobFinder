#ifndef JOBSEARCH_H
#define JOBSEARCH_H

#include <vector>
#include <algorithm>
#include <string>
#include "Job.h"

// Simplified search class for jobs
class JobSearch {
public:
    // Filter jobs by location
    static vector<Job> filterByLocation(const vector<Job>& jobs, const string& location) {
        vector<Job> results;
        for (const auto& job : jobs) {
            if (job.getLocation() == location) {
                results.push_back(job);
            }
        }
        return results;
    }

    // Filter jobs by salary range
    static vector<Job> filterBySalary(const vector<Job>& jobs, double minSalary, double maxSalary) {
        vector<Job> results;
        for (const auto& job : jobs) {
            double salary = job.getSalary();
            if (salary >= minSalary && salary <= maxSalary) {
                results.push_back(job);
            }
        }
        return results;
    }

    // Filter jobs by keyword in title or description
    static vector<Job> filterByKeyword(const vector<Job>& jobs, const string& keyword) {
        vector<Job> results;
        for (const auto& job : jobs) {
            if (job.getTitle().find(keyword) != string::npos ||
                job.getDescription().find(keyword) != string::npos) {
                results.push_back(job);
            }
        }
        return results;
    }

    // Sort jobs by salary (ascending or descending)
    static vector<Job> sortBySalary(const vector<Job>& jobs, bool ascending = true) {
        vector<Job> sortedJobs = jobs;
        if (ascending) {
            sort(sortedJobs.begin(), sortedJobs.end(),
                     [](const Job& a, const Job& b) { return a.getSalary() < b.getSalary(); });
        } else {
            sort(sortedJobs.begin(), sortedJobs.end(),
                     [](const Job& a, const Job& b) { return a.getSalary() > b.getSalary(); });
        }
        return sortedJobs;
    }
};

#endif // JOBSEARCH_H
