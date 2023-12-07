//eda alparslan 22102334
#include <iostream>
#include "employee.h"
#include "issue.h"
using namespace std;


class IssueTrackingSystem{
public:
IssueTrackingSystem();
~IssueTrackingSystem();
void addEmployee( const string name, const string title );
void removeEmployee( const string name );
void addIssue( const int issueId, const string description, const string
assigneeName );
void removeIssue( const int issueId );
void changeAssignee( const string previousAssignee, const string newAssignee );
void showAllEmployees() const;
void showAllIssues() const;
void showEmployee( const string name ) const;
void showIssue( const int issueId ) const;
bool employeeExists(const string name) const;
Employee& findEmployee(const string name) const;
Issue& findIssue(const int issueId) const;
bool issueExists(const int id) const;

private:
    Employee* employees;
    Issue* issues;
    int numOfEmployees;
    int numOfIssues;
};




