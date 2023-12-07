//eda alparslan 22102334
#include <iostream>
#include "issue.h"

using namespace std;

Issue::Issue(){}
Issue::Issue(int id, string description){
    setIssueId(id);
    setDescription(description);
}

int Issue::getIssueId(){return issueId;}
string Issue::getDescription(){return description;}
Employee Issue::getAssignee(){return assignee;}

void Issue::setIssueId(int id){
    issueId = id;
}
void Issue::setDescription(string descriptionInput){
    description = descriptionInput;
}
void Issue::setAssignee(Employee assigneeInput){
    assignee = assigneeInput;
}
