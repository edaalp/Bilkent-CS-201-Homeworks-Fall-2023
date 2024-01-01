#include "contentCreator.h"
using namespace std;
contentCreator::contentCreator(int id, string name){
    creatorId = id;
    creatorName = name;
    followers =  new LinkedSortedList<int>();
    contents =  new LinkedSortedList<int>();

    numOfFollowers = 0;
}
LinkedSortedList<int>* contentCreator::getFollowers(){ return followers;}
LinkedSortedList<int>* contentCreator::getContents() { return contents;}
string contentCreator::getCreatorName()const {return creatorName;}
int contentCreator::getCreatorId()const {return creatorId;}


bool contentCreator::operator> (const contentCreator& second) const{
return (getCreatorId()>second.getCreatorId())
;}
bool contentCreator::operator< (const contentCreator& second)const {
return (getCreatorId()<second.getCreatorId())
;}
/*bool contentCreator::operator== (const contentCreator& second)const{
return (getCreatorId()==second.getCreatorId())
;}*/
bool contentCreator::operator!= (const contentCreator& second)const{
return (getCreatorId()!=second.getCreatorId())
;}
