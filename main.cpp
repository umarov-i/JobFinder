#include <iostream>
#include <string>
#include "JobSeeker.h"
#include "Employer.h"
#include "Job.h"
#include "JobApplication.h"
#include "SearchEngine.h"
#include "Database.h"
#include "NotificationSystem.h"


int main() {
    Database* db = Database::getInstance();
    NotificationSystem notificationSystem;
    SearchEngine<Job> jobSearchEngine;


    // Sample data
    JobSeeker js1("john_doe", "password", "john@example.com", "123-456-7890");
    js1.addSkill("C++");
    js1.addSkill("Java");
    js1.addExperience("Software Developer at XYZ Corp (2018-2020)");
    db->addJobSeeker(js1);

    Employer emp1("acme_corp", "password", "hr@acme.com", "987-654-3210", "ACME Corporation", "Technology", "Leading tech company");
    db->addEmployer(emp1);

    Job job1(1, "Software Engineer", "Develop and maintain software applications", "C++, Java, 3+ years experience", "New York", 85000.0, "acme_corp");
    Job job2(2, "Web Developer", "Create responsive web applications", "HTML, CSS, JavaScript, React", "San Francisco", 95000.0, "acme_corp");
    Job job3(3, "Data Scientist", "Analyze and interpret complex data", "Python, R, Machine Learning", "Boston", 110000.0, "acme_corp");

    db->addJob(job1);
    db->addJob(job2);
    db->addJob(job3);

    emp1.postJob(job1);
    emp1.postJob(job2);
    emp1.postJob(job3);



    return 0;
}
