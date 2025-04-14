#ifndef JOB_H
#define JOB_H

#include <string>
#include "JobStatus.h"

class Job {
private:
    int jobId;
    string title;
    string description;
    string requirements;
    string location;
    double salary;
    string employerUsername;
    JobStatus status;

public:
    Job(int jobId, string title, string description, string requirements,
        string location, double salary, string employerUsername)
        : jobId(jobId), title(title), description(description), requirements(requirements),
          location(location), salary(salary), employerUsername(employerUsername), status(JobStatus::OPEN) {}

    int getJobId() const { return jobId; }

    string getTitle() const { return title; }
    void setTitle(string title) { this->title = title; }

    string getDescription() const { return description; }
    void setDescription(string description) { this->description = description; }

    string getRequirements() const { return requirements; }
    void setRequirements(string requirements) { this->requirements = requirements; }

    string getLocation() const { return location; }
    void setLocation(string location) { this->location = location; }

    double getSalary() const { return salary; }
    void setSalary(double salary) { this->salary = salary; }

    string getEmployerUsername() const { return employerUsername; }

    JobStatus getStatus() const { return status; }
    void setStatus(JobStatus status) { this->status = status; }
};

#endif // JOB_H
