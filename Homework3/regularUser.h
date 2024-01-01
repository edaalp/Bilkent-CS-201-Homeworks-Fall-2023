//Eda Alparslan 22102334 Section 3
#include <iostream>
using namespace std;
class regularUser{
public:
    regularUser();
    regularUser(const string userName, const int userId);
    void setUserId(const int newId = 0);
    void setUserName(const string newName = "");
    string getUserName() const;
    int getUserId() const;
    bool operator> (const regularUser& second) const;
    bool operator< (const regularUser& second)const;
    //bool operator= (const regularUser& second)const;
    bool operator!= (const regularUser& second)const;
private:
    string userName;
    int userId;

















};
