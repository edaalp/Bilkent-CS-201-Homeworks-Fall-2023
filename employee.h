//eda alparslan 22102334
#include <iostream>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;
class Employee{
public:
    Employee();
    int* getAssignedIssues();
    string getTitle();
    string getEmployeeName();
    int getNumOfIssues();

    void setTitle(const string inputTitle);
    void setName(const string name);
    void addIsuue(const int issueId);
    void removeIssue(const int issueId);
    void setAssignedIssues(int* assigned);
    void setNumOfIssues(const int newissues);


private:
    string title;
    string employeeName;
    int* assignedIssues;
    int numOfIssues;

};
#endif // EMPLOYEE_H
