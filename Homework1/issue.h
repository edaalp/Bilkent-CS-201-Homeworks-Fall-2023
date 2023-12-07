//eda alparslan 22102334
#include <iostream>
#include "employee.h"
#ifndef ISSUE_H
#define ISSUE_H
using namespace std;
class Issue{
public:
    Issue();
    Issue(int id, string description);
    int getIssueId();
    string getDescription();
    Employee getAssignee();

    void setIssueId(int id);
    void setDescription(string descriptionInput);
    void setAssignee(Employee assigneeInput);


private:
    int issueId;
    string description;
    Employee assignee;

#endif // EMPLOYEE_H










};
