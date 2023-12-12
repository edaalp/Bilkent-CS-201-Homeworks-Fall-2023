//eda alparslan 22102334
#include <iostream>
#include "IssueTrackingSystem.h"
#include <string>
using namespace std;

IssueTrackingSystem::IssueTrackingSystem(){
    employees = new Employee[20];
    issues = new Issue[20];
    numOfEmployees = 0;
    numOfIssues = 0;
}
IssueTrackingSystem::~IssueTrackingSystem(){}

void IssueTrackingSystem::addEmployee(const string name, const string title){
    if(!employeeExists(name)){
        Employee tempEmployee = Employee();
        tempEmployee.setTitle(title);
        tempEmployee.setName(name);
        employees[numOfEmployees] = tempEmployee;
        numOfEmployees++;
        cout << "Added employee " << name <<"." <<endl;
    }
    else cout << "Cannot add employee. Employee with name " << name << " already exists."<< endl;
}

void IssueTrackingSystem::showAllEmployees()const {
    cout<<"Employees in the system:"<< endl;
    if(numOfEmployees == 0) cout << "None" << endl;
    for(int i = 0; i< numOfEmployees; i++){
        Employee temp = employees[i];
        cout<<temp.getEmployeeName()<< ", " << temp.getTitle() << ", " << temp.getNumOfIssues() << " issue(s)." <<endl;
    }

}
void IssueTrackingSystem::showEmployee(const string name) const{
    if(employeeExists(name)){
        Employee temp = findEmployee(name);
        cout<<temp.getEmployeeName()<< ", " << temp.getTitle() << ", " << temp.getNumOfIssues() << " issue(s)." <<endl;
    }
    else cout << "Cannot show employee. There is no employee with name " << name <<"." << endl;
}
void IssueTrackingSystem::removeEmployee( const string name ){
    int index = 0;

    if (employeeExists(name)){
        if(findEmployee(name).getNumOfIssues()!= 0) cout << "Cannot remove employee. " << name <<" has assigned issues."<< endl;
         else{
         for(int i = 0; i < numOfEmployees; i++){
            if (employees[i].getEmployeeName()==name){
                numOfEmployees--;
                for (int j = i; j < numOfEmployees ; j++){
                    employees[j] = employees[j+1];
                }
                cout << "Removed employee " << name << "." << endl;
            }
        }}
    }
    else cout << "Cannot remove employee. There is no employee with name " << name << "." << endl;
}

Employee& IssueTrackingSystem::findEmployee(const string name) const{
    if (employeeExists(name)){
        for(int i = 0; i < numOfEmployees; i++){
            if (employees[i].getEmployeeName()==name)
                return employees[i];
        }
    }
    else{
        Employee emptyEmployee = Employee();
        return emptyEmployee;
    }
}

bool IssueTrackingSystem::employeeExists(const string name) const{
    if(numOfEmployees==0) return false;
    else{
    bool temp = false;
    for (int i = 0; i< numOfEmployees; i++){
        if(employees[i].getEmployeeName()==name){
            temp=true;
        }
    }
    return temp;
    }
}

bool IssueTrackingSystem::issueExists(const int id) const{
    if(numOfIssues==0) return false;
    else{
    bool temp = false;
    for (int i = 0; i< numOfIssues; i++){
        if(issues[i].getIssueId()==id){
            temp=true;
        }
    }
    return temp;
    }
}

void IssueTrackingSystem::addIssue( const int issueId, const string description, const string assigneeName){
   if(!employeeExists(assigneeName)) cout << "Cannot add issue. There is no employee with name " << assigneeName << "." << endl;
   else if (!issueExists(issueId)){
        Issue tempIssue = Issue(issueId, description);
        tempIssue.setAssignee(findEmployee(assigneeName));
        issues[numOfIssues] = tempIssue;
        numOfIssues++;
        findEmployee(assigneeName).addIsuue(issueId);
        cout << "Added issue " << issueId <<"."<< endl;
    }
    else cout << "Cannot add issue. Issue with ID " << issueId << " already exists."<< endl;


}

void IssueTrackingSystem::removeIssue( const int issueId ){
    if (issueExists(issueId)){
    for (int i = 0; i < numOfIssues; i++){
        if (issues[i].getIssueId()==issueId){
            cout <<"Removed issue " << issueId << "."<<endl;
            numOfIssues--;
            for (int j = i; j < numOfIssues; j++){
                issues[j] = issues[j+1];
            }
            }
        }
    for (int k = 0; k< numOfEmployees;k++){
            employees[k].removeIssue(issueId);
    }
    }
    else cout << "Cannot remove issue. There is no issue with ID " << issueId << "." << endl;
}

void IssueTrackingSystem::showAllIssues() const{
    cout<<"Issues in the system:"<< endl;
    if (numOfIssues==0) cout << "None" <<endl;
    for(int i = 0; i< numOfEmployees; i++){
        Employee current = employees[i];
        int* currentIssues = current.getAssignedIssues();
        for (int j = 0; j < current.getNumOfIssues(); j++){
            Issue currentIssue = findIssue(currentIssues[j]);
            cout << currentIssue.getIssueId() << ", " << currentIssue.getDescription()<< ", " << currentIssue.getAssignee().getEmployeeName() <<"." << endl;
        }
    }
}

void IssueTrackingSystem::changeAssignee(const string previousAssignee, const string newAssignee) {
        if(employeeExists(previousAssignee)&&employeeExists(newAssignee)){
            cout<<previousAssignee << "'s issues are transferred to "<< newAssignee <<"."<< endl;
            Employee& first = findEmployee(previousAssignee);
            Employee& second = findEmployee(newAssignee);
            int* newArray = second.getAssignedIssues();
            for(int i = 0; i < first.getNumOfIssues();i++){
                newArray[second.getNumOfIssues()+i]=first.getAssignedIssues()[i];
            }

            second.setAssignedIssues(newArray);
            first.setAssignedIssues(new int[10]);
            second.setNumOfIssues(first.getNumOfIssues()+second.getNumOfIssues());
            first.setNumOfIssues(0);

            for (int i = 0; i<numOfIssues; i++){
                if(issues[i].getAssignee().getEmployeeName()==previousAssignee){
                    issues[i].setAssignee(findEmployee(newAssignee));
                }
            }

        }
        else cout<< "Cannot change assignee. Previous or/and new assignee does not exist." << endl;
}

void IssueTrackingSystem::showIssue( const int issueId ) const{
    if(issueExists(issueId)){
    Issue temp = findIssue(issueId);
    cout<< issueId << ", " << temp.getDescription() << ", " << temp.getAssignee().getEmployeeName() << "." << endl;

    }
    else cout << "Cannot show issue. There is no issue with ID " << issueId <<"."<<endl;


}

Issue& IssueTrackingSystem::findIssue(const int issueId) const{
    if (issueExists(issueId)){
        for(int i = 0; i < numOfIssues; i++){
            if (issues[i].getIssueId()==issueId)
                return issues[i];
        }
    }
    else{
        Issue emptyIssue = Issue();
        return emptyIssue;
    }








}

