#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include <iostream>
#include "JobSeeker.h"
#include "Employer.h"
#include "Job.h"
#include "JobApplication.h"

class NotificationSystem {
public:
    void sendApplicationNotification(const JobSeeker& jobSeeker, const Job& job) {
        cout << "Notification: " << jobSeeker.getUsername()
                  << " has applied for the job: " << job.getTitle() << endl;
    }

    void sendInterviewInvitation(const JobSeeker& jobSeeker, const Job& job) {
        cout << "Notification: " << jobSeeker.getUsername()
                  << " has been invited for an interview for the job: " << job.getTitle() << endl;
    }

    void sendStatusUpdateNotification(const JobSeeker& jobSeeker, const JobApplication& application) {
        cout << "Notification: " << jobSeeker.getUsername()
                  << " your application status has been updated to: ";

        switch(application.getStatus()) {
            case ApplicationStatus::PENDING:
                cout << "Pending";
            break;
            case ApplicationStatus::REVIEWED:
                cout << "Reviewed";
            break;
            case ApplicationStatus::ACCEPTED:
                cout << "Accepted";
            break;
            case ApplicationStatus::REJECTED:
                cout << "Rejected";
            break;
        }

        cout << " for application ID: " << application.getApplicationId() << endl;
    }

    void sendNewApplicantNotification(const Employer& employer, const JobApplication& application) {
        cout << "Notification: " << employer.getCompanyName()
                  << " has received a new application from " << application.getJobSeekerUsername()
                  << " for job ID: " << application.getJobId() << endl;
    }
};

#endif // NOTIFICATIONSYSTEM_H
