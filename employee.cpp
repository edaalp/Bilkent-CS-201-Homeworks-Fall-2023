//eda alparslan 22102334
#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee(){
    assignedIssues = new int[10];
    numOfIssues = 0;
}


int* Employee::getAssignedIssues(){return assignedIssues;}
string Employee::getTitle(){return title;}
string Employee::getEmployeeName(){return employeeName;}
int Employee::getNumOfIssues(){return numOfIssues;}

void Employee::setTitle(const string inputTitle){
    title = inputTitle;
};
void Employee::setName(const string name){
    employeeName=name;
};
void Employee::addIsuue(const int issueId){
    assignedIssues[numOfIssues]=issueId;
     numOfIssues++;
};
void Employee::removeIssue(const int issueId){
    for (int i = 0; i< numOfIssues; i++){
        if(assignedIssues[i] == issueId){
            numOfIssues--;
            for(int j = i; j< numOfIssues; j++){
                assignedIssues[j] = assignedIssues[j+1];
            }
        }
    }

}

 void Employee::setAssignedIssues(int* assigned){
    assignedIssues=assigned;
 }

  void Employee::setNumOfIssues(const int newissues){
    numOfIssues = newissues;

  }



