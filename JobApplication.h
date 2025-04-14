#ifndef JOBAPPLICATION_H
#define JOBAPPLICATION_H

#include <string>
#include "ApplicationStatus.h"
#include "Date.h"

class JobApplication {
private:
    int applicationId;
    int jobId;
    string jobSeekerUsername;
    string coverLetter;
    ApplicationStatus status;
    Date applicationDate;

public:
    JobApplication(int applicationId, int jobId, string jobSeekerUsername, string coverLetter)
        : applicationId(applicationId), jobId(jobId), jobSeekerUsername(jobSeekerUsername),
          coverLetter(coverLetter), status(ApplicationStatus::PENDING), applicationDate() {}

    int getApplicationId() const { return applicationId; }

    int getJobId() const { return jobId; }

    string getJobSeekerUsername() const { return jobSeekerUsername; }

    string getCoverLetter() const { return coverLetter; }
    void setCoverLetter(string letter) { coverLetter = letter; }

    ApplicationStatus getStatus() const { return status; }
    void setStatus(ApplicationStatus newStatus) { status = newStatus; }

    Date getApplicationDate() const { return applicationDate; }
};

#endif // JOBAPPLICATION_H
