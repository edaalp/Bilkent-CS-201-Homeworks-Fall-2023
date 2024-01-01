//Eda Alparslan 22102334 Section 3
#include "regularUser.h"
using namespace std;



regularUser::regularUser(const string userName, const int userId){
    setUserId(userId);
    setUserName(userName);
}
void regularUser::setUserName(const string newName){userName= newName;}
void regularUser::setUserId(const int newId){userId=newId;}

string regularUser::getUserName() const{return userName;}
int regularUser::getUserId()const{ return userId;}

bool regularUser::operator> (const regularUser& second)const{
return (getUserId()>second.getUserId());}
bool regularUser::operator< (const regularUser& second)const{
return (getUserId()<second.getUserId());}
/*bool regularUser::operator= (const regularUser& second)const{
return (getUserId()==second.getUserId());}*/
bool regularUser::operator!= (const regularUser& second)const{
return (getUserId()!=second.getUserId());}
