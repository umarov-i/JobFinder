#include <iostream>
#include <string>
#include <iomanip>
#include "JobSeeker.h"
#include "Employer.h"
#include "Job.h"
#include "JobApplication.h"
#include "JobSearch.h"
#include "Database.h"
using namespace std;
// Helper function to print a section header
void printHeader(const string& title) {
    cout << "\n=== " << title << " ===\n";
}

int main() {
    Database db;

    // ==================== JOBSEEKER CLASS DEMONSTRATION ====================
    printHeader("JOBSEEKER CLASS");

    // Create a JobSeeker
    JobSeeker js1("john_doe", "password", "john@example.com", "123-456-7890");
    cout << "Created JobSeeker: " << js1.getUsername() << "\n";

    // Demonstrate getters
    cout << "Username: " << js1.getUsername() << "\n";
    cout << "Email: " << js1.getEmail() << "\n";
    cout << "Contact: " << js1.getContactInfo() << "\n";

    // Demonstrate setters
    js1.setEmail("john.updated@example.com");
    cout << "Updated email: " << js1.getEmail() << "\n";

    // Demonstrate addSkill
    js1.addSkill("C++");
    js1.addSkill("Java");
    cout << "Added skills. Skills count: " << js1.getSkills().size() << "\n";

    // Demonstrate addExperience
    js1.addExperience("Software Developer at XYZ Corp (2018-2020)");
    cout << "Added experience. Experience count: " << js1.getExperience().size() << "\n";

    // Demonstrate uploadResume
    js1.uploadResume("/path/to/resume.pdf");
    cout << "Resume path: " << js1.getResume() << "\n";

    // Demonstrate displayProfile
    cout << "Displaying profile:\n";
    js1.displayProfile();

    // Demonstrate authenticate
    cout << "Authentication (correct): ";
    if (js1.authenticate("john_doe", "password")) {
        cout << "Success\n";
    } else {
        cout << "Failed\n";
    }
    cout << "Authentication (incorrect): ";
    if (js1.authenticate("john_doe", "wrong")) {
        cout << "Success\n";
    } else {
        cout << "Failed\n";
    }

    // Add to database
    db.addJobSeeker(js1);
    cout << "Added JobSeeker to database\n";

    // ==================== EMPLOYER CLASS DEMONSTRATION ====================
    printHeader("EMPLOYER CLASS");

    // Create an Employer
    Employer emp1("acme_corp", "password", "hr@acme.com", "987-654-3210",
                 "ACME Corporation", "Technology", "Leading tech company");
    cout << "Created Employer: " << emp1.getUsername() << "\n";

    // Demonstrate getters
    cout << "Username: " << emp1.getUsername() << "\n";
    cout << "Company: " << emp1.getCompanyName() << "\n";
    cout << "Industry: " << emp1.getIndustry() << "\n";
    cout << "Description: " << emp1.getCompanyDescription() << "\n";

    // Demonstrate setters
    emp1.setCompanyDescription("Global leader in innovative technology solutions");
    cout << "Updated description: " << emp1.getCompanyDescription() << "\n";

    // Demonstrate displayProfile
    cout << "Displaying profile:\n";
    emp1.displayProfile();

    // Add to database
    db.addEmployer(emp1);
    cout << "Added Employer to database\n";

    // ==================== JOB CLASS DEMONSTRATION ====================
    printHeader("JOB CLASS");

    // Create Jobs
    Job job1(1, "Software Engineer", "Develop and maintain software applications",
             "C++, Java, 3+ years experience", "New York", 85000.0, "acme_corp");
    Job job2(2, "Web Developer", "Create responsive web applications",
             "HTML, CSS, JavaScript, React", "San Francisco", 95000.0, "acme_corp");
    Job job3(3, "Data Scientist", "Analyze and interpret complex data",
             "Python, R, Machine Learning", "Boston", 110000.0, "acme_corp");

    cout << "Created Jobs with IDs: " << job1.getJobId() << ", "
              << job2.getJobId() << ", " << job3.getJobId() << "\n";

    // Demonstrate getters
    cout << "Job 1 - Title: " << job1.getTitle() << "\n";
    cout << "Job 1 - Location: " << job1.getLocation() << "\n";
    cout << "Job 1 - Salary: $" << job1.getSalary() << "\n";
    cout << "Job 1 - Status: " << (job1.getStatus() == JobStatus::OPEN ? "Open" : "Not Open") << "\n";

    // Demonstrate setters
    job1.setTitle("Senior Software Engineer");
    job1.setSalary(95000.0);
    cout << "Updated title: " << job1.getTitle() << "\n";
    cout << "Updated salary: $" << job1.getSalary() << "\n";

    // Add to database
    db.addJob(job1);
    db.addJob(job2);
    db.addJob(job3);
    cout << "Added Jobs to database\n";

    // Demonstrate postJob in Employer
    emp1.postJob(job1);
    emp1.postJob(job2);
    emp1.postJob(job3);
    cout << "Employer posted jobs. Posted job count: " << emp1.getPostedJobs().size() << "\n";

    // ==================== DATE CLASS DEMONSTRATION ====================
    printHeader("DATE CLASS");

    // Create Date objects
    Date currentDate;
    Date specificDate(15, 6, 2023);

    cout << "Current date: " << currentDate.toString() << "\n";
    cout << "Specific date: " << specificDate.toString() << "\n";

    // ==================== JOBAPPLICATION CLASS DEMONSTRATION ====================
    printHeader("JOBAPPLICATION CLASS");

    // Create JobApplication objects
    JobApplication app1(1, 1, "john_doe", "I am very interested in this position...");
    JobApplication app2(2, 2, "john_doe", "I have extensive experience with web development...");

    cout << "Created applications with IDs: " << app1.getApplicationId() << ", "
              << app2.getApplicationId() << "\n";

    // Demonstrate getters
    cout << "App 1 - Job ID: " << app1.getJobId() << "\n";
    cout << "App 1 - Applicant: " << app1.getJobSeekerUsername() << "\n";
    cout << "App 1 - Status: " << (app1.getStatus() == ApplicationStatus::PENDING ? "Pending" : "Not Pending") << "\n";
    cout << "App 1 - Date: " << app1.getApplicationDate().toString() << "\n";

    // Demonstrate setters
    app1.setCoverLetter("Updated cover letter");
    app1.setStatus(ApplicationStatus::REVIEWED);
    cout << "Updated cover letter length: " << app1.getCoverLetter().length() << "\n";
    cout << "Updated status: " << (app1.getStatus() == ApplicationStatus::REVIEWED ? "Reviewed" : "Not Reviewed") << "\n";

    // Add to database
    db.addApplication(app1);
    db.addApplication(app2);
    cout << "Added Applications to database\n";

    // Demonstrate applyForJob in JobSeeker
    js1.applyForJob(1);
    js1.applyForJob(2);
    cout << "JobSeeker applied for jobs. Applied job count: " << js1.getAppliedJobs().size() << "\n";

    // ==================== JOBSEARCH CLASS DEMONSTRATION ====================
    printHeader("JOBSEARCH CLASS");

    // Get all jobs from database
    vector<Job> allJobs = db.getAllJobs();

    // Demonstrate filterByKeyword
    vector<Job> keywordResults = JobSearch::filterByKeyword(allJobs, "software");
    cout << "Jobs containing 'software': " << keywordResults.size() << "\n";

    // Demonstrate filterByLocation
    vector<Job> locationResults = JobSearch::filterByLocation(allJobs, "San Francisco");
    cout << "Jobs in San Francisco: " << locationResults.size() << "\n";

    // Demonstrate filterBySalary
    vector<Job> salaryResults = JobSearch::filterBySalary(allJobs, 90000.0, 120000.0);
    cout << "Jobs with salary $90k-$120k: " << salaryResults.size() << "\n";

    // Demonstrate sortBySalary
    vector<Job> sortedJobs = JobSearch::sortBySalary(allJobs, true);
    cout << "Jobs sorted by salary (ascending):\n";
    for (const auto& job : sortedJobs) {
        cout << "- Job ID: " << job.getJobId() << ", Salary: $" << job.getSalary() << "\n";
    }

    // ==================== DATABASE CLASS DEMONSTRATION ====================
    printHeader("DATABASE CLASS");

    // Demonstrate findJobSeeker
    JobSeeker* foundJobSeeker = db.findJobSeeker("john_doe");
    JobSeeker* notFoundJobSeeker = db.findJobSeeker("nonexistent");
    cout << "Find JobSeeker 'john_doe': " << (foundJobSeeker ? "Found" : "Not found") << "\n";
    cout << "Find JobSeeker 'nonexistent': " << (notFoundJobSeeker ? "Found" : "Not found") << "\n";

    // Demonstrate findEmployer
    Employer* foundEmployer = db.findEmployer("acme_corp");
    cout << "Find Employer 'acme_corp': " << (foundEmployer ? "Found" : "Not found") << "\n";

    // Demonstrate findJob
    Job* foundJob = db.findJob(1);
    cout << "Find Job with ID 1: " << (foundJob ? "Found" : "Not found") << "\n";

    // Demonstrate getAllJobs
    vector<Job> jobs = db.getAllJobs();
    cout << "Total jobs in database: " << jobs.size() << "\n";

    // Demonstrate getApplicationsForJob
    vector<JobApplication> applicationsForJob1 = db.getApplicationsForJob(1);
    cout << "Applications for Job ID 1: " << applicationsForJob1.size() << "\n";

    // Demonstrate getApplicationsByJobSeeker
    vector<JobApplication> applicationsByJohnDoe = db.getApplicationsByJobSeeker("john_doe");
    cout << "Applications by 'john_doe': " << applicationsByJohnDoe.size() << "\n";

    // Demonstrate updateApplicationStatus
    bool updateResult = db.updateApplicationStatus(1, ApplicationStatus::ACCEPTED);
    cout << "Update application status: " << (updateResult ? "Success" : "Failed") << "\n";

    // Check the updated status
    vector<JobApplication> updatedApplications = db.getApplicationsForJob(1);
    if (!updatedApplications.empty()) {
        cout << "Updated status: " << (updatedApplications[0].getStatus() == ApplicationStatus::ACCEPTED ? "Accepted" : "Not Accepted") << "\n";
    }

    cout << "\nAll functions have been demonstrated successfully.\n";

    return 0;
}
