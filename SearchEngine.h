#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <functional>
#include <algorithm>
#include "Job.h"

// Template class for searching
template <typename T>
class SearchEngine {
public:
    // Generic search function that takes a predicate
    vector<T> search(const vector<T>& items, function<bool(const T&)> predicate) {
        vector<T> results;
        for (const auto& item : items) {
            if (predicate(item)) {
                results.push_back(item);
            }
        }
        return results;
    }

    // Specialized function for filtering by location
    vector<T> filterByLocation(const vector<T>& items, const string& location) {
        return search(items, [&location](const T& item) {
            return item.getLocation() == location;
        });
    }

    // Specialized function for filtering by salary range
    vector<T> filterBySalary(const vector<T>& items, double minSalary, double maxSalary) {
        return search(items, [minSalary, maxSalary](const T& item) {
            double salary = item.getSalary();
            return salary >= minSalary && salary <= maxSalary;
        });
    }

    // Template function for sorting
    template <typename Comparator>
    vector<T> sortItems(const vector<T>& items, Comparator comp) {
        vector<T> sortedItems = items;
        sort(sortedItems.begin(), sortedItems.end(), comp);
        return sortedItems;
    }
};

// Specialization for Job type
template <>
class SearchEngine<Job> {
public:
    vector<Job> search(const vector<Job>& jobs, function<bool(const Job&)> predicate) {
        vector<Job> results;
        for (const auto& job : jobs) {
            if (predicate(job)) {
                results.push_back(job);
            }
        }
        return results;
    }

    vector<Job> filterByLocation(const vector<Job>& jobs, const string& location) {
        return search(jobs, [&location](const Job& job) {
            return job.getLocation() == location;
        });
    }

    vector<Job> filterBySalary(const vector<Job>& jobs, double minSalary, double maxSalary) {
        return search(jobs, [minSalary, maxSalary](const Job& job) {
            double salary = job.getSalary();
            return salary >= minSalary && salary <= maxSalary;
        });
    }

    vector<Job> filterByKeyword(const vector<Job>& jobs, const string& keyword) {
        return search(jobs, [&keyword](const Job& job) {
            return job.getTitle().find(keyword) != string::npos ||
                   job.getDescription().find(keyword) != string::npos;
        });
    }

    vector<Job> sortBySalary(const vector<Job>& jobs, bool ascending = true) {
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

#endif // SEARCHENGINE_H
