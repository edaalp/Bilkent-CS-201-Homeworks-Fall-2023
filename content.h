//Eda Alparslan 22102334 Section 3
#ifndef CONTENT_H
#define CONTENT_H
#include <iostream>
using namespace std;

class content{
public:
    content(int creatorid, int contentid, string name);
    bool operator> (const content second) const;
    bool operator< (content second)const;
    //bool operator= (content second)const;
    bool operator!= (content second)const;
    int getContentId() const;
    string getContentName()const;
    int getCreatorsId() const;


private:
    int creatorsId;
    int contentId;
    string contentName;
};
#endif // CONTENT_H
