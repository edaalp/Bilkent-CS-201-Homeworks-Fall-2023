//Eda Alparslan 22102334 Section 3
#include <iostream>
#include "LinkedSortedList.h"
#include "content.h"
#ifndef CONTENTCREATOR_H
#define CONTENTCREATOR_H

using namespace std;
class contentCreator{
public:
    contentCreator(int id, string name);
    void setCreatorName(const string newName);
    void setCreatorId(const int newId);
    string getCreatorName() const;
    int getCreatorId() const;
    LinkedSortedList<int>* getFollowers();
    LinkedSortedList<int>* getContents();
    void addContent(int contentId);
    bool operator> (const contentCreator& second) const;
    bool operator< (const contentCreator& second)const;
    //bool operator= (const contentCreator& second)const;
    bool operator!= (const contentCreator& second)const;



private:
    string creatorName;
    int creatorId;
    LinkedSortedList<int>* followers;
    LinkedSortedList<int>* contents;
    int numOfFollowers;
};
#endif // CONTENTCREATOR_H
