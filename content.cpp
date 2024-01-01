//Eda Alparslan 22102334 Section 3

#include "content.h"
using namespace std;
content::content(int creatorid, int contentid, string name){
    creatorsId = creatorid;
    contentId = contentid;
    contentName = name;
}

int content::getContentId()const {return contentId;}
string content::getContentName()const{return contentName;}
int content::getCreatorsId()const {return creatorsId;}

bool content::operator> (content second)const{
return (getContentId()>second.getContentId())
;}
bool content::operator< (content second) const{
return (getContentId()<second.getContentId())
;}
/*bool content::operator= (content second)const{
return (getContentId()==second.getContentId())
;}*/
bool content::operator!= (content second)const{
return (getContentId()!=second.getContentId())
;}
