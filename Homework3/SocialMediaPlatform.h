//Eda Alparslan 22102334 Section 3
#include "LinkedSortedList.h"
#include "content.h"
#include "contentCreator.h"
#include "regularUser.h"
using namespace std;
class SocialMediaPlatform{
public:
    SocialMediaPlatform();
    ~SocialMediaPlatform();
    void addRegularUser( const int regularUserId, const string name );
    void removeRegularUser( const int regularUserId );
    void addContentCreator( const int contentCreatorId, const string name );
    void removeContentCreator( const int contentCreatorId );
    void addContent( const int contentCreatorId, const int contentId, const string title );
    void removeContent( const int contentCreatorId, const int contentId );
    void followContentCreator( const int regularUserId, const int contentCreatorId );
    void unfollowContentCreator( const int regularUserId, const int contentCreatorId);
    void showFollowersOf( const int contentCreatorId ) const;
    void showContentsOf( const int contentCreatorId ) const;
    void showAllRegularUsers( ) const;
    void showAllContentCreators( ) const;

private:
    LinkedSortedList<regularUser>* regularUsers;
    LinkedSortedList<contentCreator>* contentCreators;
    LinkedSortedList<content>* contents;
};
